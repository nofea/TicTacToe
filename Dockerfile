FROM dokken/ubuntu-22.04

WORKDIR /TicTacToe

COPY . .

RUN apt -y update

RUN apt -y install $(cat requirements.txt)

CMD [ "bash" ]
