# defines the compiler used
CC = gcc
# defines the build directory
BUILD_DIR = bin
# defines object directory
OBJ_DIR = obj
# defines the executable name
EXEC_NAME = CYdventure

# compile tout
all: 
	# linux os ci dessous #
	# mkdir -p $(BUILD_DIR)
	# mkdir -p $(OBJ_DIR)
	

	# windows os ci dessous #
	# créer les dossier pour les objets et l'executable
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	
	# compile les fichiers .c en objet (pareil pour les 2 os)
	$(CC) main.c -o ./$(OBJ_DIR)/main.c.o -c
	$(CC) function.c -o ./$(OBJ_DIR)/function.c.o -c
	$(CC) save.c -o ./$(OBJ_DIR)/save.c.o -c
	$(CC) player.c -o ./$(OBJ_DIR)/player.c.o -c
	$(CC) fight.c -o ./$(OBJ_DIR)/fight.c.o -c
	
	# compile les objets en l'executable
	$(CC) ./$(OBJ_DIR)/function.c.o ./$(OBJ_DIR)/main.c.o ./$(OBJ_DIR)/save.c.o ./$(OBJ_DIR)/player.c.o ./$(OBJ_DIR)/fight.c.o -o ./$(BUILD_DIR)/$(EXEC_NAME).exe

# efface les fichiers compilés
clean:
	# linux os ci dessous #
	# rmdir /s /q $(BUILD_DIR)
	# rmdir /s /q $(OBJ_DIR)


	# windows os ci dessous #
	if exist $(BUILD_DIR)\$(EXEC_NAME).exe del $(BUILD_DIR)\$(EXEC_NAME).exe
	if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
	if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)