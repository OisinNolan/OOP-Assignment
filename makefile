CC=g++
CFLAGS=
BFLAGS = -lm

MAIN=main
SRCS= Catalogue.cpp Trajet.cpp TrajetSimple.cpp TrajetCompose.cpp main.cpp TrajetList.cpp
OBJS=$(SRCS:.cpp=.o)

$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : launch
launch : $(MAIN)
	./$(MAIN)

.PHONY : clean
clean:
	rm -f $(MAIN) *.o core
