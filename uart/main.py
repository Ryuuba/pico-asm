from machine import Pin, UART, I2C
from utime import sleep
from ssd1306 import SSD1306_I2C

def main() -> None:
    uart = UART(0, baudrate=9600, tx=Pin(12), rx=Pin(13))
    i2c = I2C(0, sda=Pin(16), scl=Pin(17), freq=400000)
    oled = SSD1306_I2C(128, 64, i2c)
    oled.text('Receiver ON', 0, 0)
    oled.show()
    while True:
        if uart.any():
            cmd = uart.read(1)
            try:
                cmd_val = int(cmd)
            except ValueError:
                print(cmd)
                oled.text(f'Error: cmd', 0, 10)
                oled.text('is not numeric', 0, 20)
            except:
                oled.text('Error: cmd unknown', 0, 10)
            else:
                print(cmd_val)
                if cmd_val == 1:
                    oled.fill(0)
                    oled.text('Running cmd 1', 0, 10)
                elif cmd_val == 2:
                    oled.fill(0)
                    oled.text('Running cmd 2', 0, 10)
                elif cmd_val == 3:
                    oled.fill(0)
                    oled.text('Running cmd 3', 0, 10)
                else:
                    oled.fill(0)
                    oled.text(f'Unknown cmd {cmd_val}', 0, 10)
            finally:
                oled.text('Receiver ON', 0, 0)
                oled.show()
            

if __name__ == '__main__':
    main()