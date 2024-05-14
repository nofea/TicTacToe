FROM ubuntu:latest

WORKDIR /TicTacToe

COPY . .

RUN apt -y update && apt -y upgrade

RUN apt -y install $(cat requirements.txt)
