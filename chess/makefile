CC = g++
CFLAGS = -g -Wall

all: chess

chess: main.o Board.o BoardPosition.o Pawn.o ChessPiece.o Rook.o Knight.o Bishop.o Queen.o King.o SequentialChessPiece.o
	$(CC) $(CFLAGS) -o chess main.o Board.o BoardPosition.o Pawn.o ChessPiece.o Rook.o Knight.o Bishop.o Queen.o King.o SequentialChessPiece.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Board.o: Board.cpp
	$(CC) $(CFLAGS) -c Board.cpp

BoardPosition.o: BoardPosition.cpp
	$(CC) $(CFLAGS) -c BoardPosition.cpp

Pawn.o: Pawn.cpp
	$(CC) $(CFLAGS) -c Pawn.cpp

ChessPiece.o: ChessPiece.cpp
	$(CC) $(CFLAGS) -c ChessPiece.cpp

Rook.o: Rook.cpp
	$(CC) $(CFLAGS) -c Rook.cpp

Knight.o: Knight.cpp
	$(CC) $(CFLAGS) -c Knight.cpp

Bishop.o: Bishop.cpp
	$(CC) $(CFLAGS) -c Bishop.cpp

Queen.o: Queen.cpp
	$(CC) $(CFLAGS) -c Queen.cpp

King.o: King.cpp
	$(CC) $(CFLAGS) -c King.cpp

SequentialChessPiece.o: SequentialChessPiece.cpp
	$(CC) $(Cflags) -c SequentialChessPiece.cpp

clean:
	$(RM) chess *.o *~
