from machine import Pin, UART, I2C
from utime import sleep

def main() -> None:
    uart = UART(0, baudrate=9600, tx=Pin(12), rx=Pin(13))
    while True:
        if uart.any():
            msg = uart.read()
            print(f'{msg} mundo')
            uart.write('mundo')
            sleep(1)
            

if __name__ == '__main__':
    main()