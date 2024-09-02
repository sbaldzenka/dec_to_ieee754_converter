# Project : dec_to_ieee754_converter
# Autor   : Siarhei Baldzenka (sbaldzenka)
# Date    : 02.09.2024

CC=gcc
APP_NAME=dec_to_ieee754_converter

SOURCES=src/main.c       \
		src/ieee754x32.c \
		src/read_file.c  \
		src/write_file.c

all:
	$(CC) $(SOURCES) -o $(APP_NAME)

clean:
	rm -R $(OUTDIR)