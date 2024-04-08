FROM ubuntu:latest

WORKDIR /TicTacToe

COPY . .

RUN apt -y update

RUN apt -y install $(cat requirements.txt)
