LIB       = -lm -lSDL -lSDLmain -lGL -lGLU -lglut
CFLAGS    = -W -Wall -ansi

SRC_PATH  = src
SRC_FILES = $(shell find $(SRC_PATH) -type f -name '*.c')

OBJ_PATH  = obj
OBJ_FILES = $(patsubst $(SRC_PATH)/%.c,$(OBJ_PATH)/%.o, $(SRC_FILES))

EXEC 	  = djk

$(EXEC): $(OBJ_FILES)
	@gcc -o $(EXEC) $(OBJ_FILES) $(LIB)
	@echo "> Compilation effectuée"
	@echo "> ./$(EXEC)"

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	@mkdir -p "$(@D)"
	@gcc -o $@ -c $< $(INCLUDE_PATH) $(CFLAGS)

clean:
	@rm obj/*.o $(EXEC)
	@echo "> Objets et exécutable nettoyés"
	@make --no-print-directory