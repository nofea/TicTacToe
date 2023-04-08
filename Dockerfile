FROM dokken/ubuntu-22.04

WORKDIR /TicTacToe

COPY . .

RUN apt update

RUN apt install -y $(cat requirements.txt)
