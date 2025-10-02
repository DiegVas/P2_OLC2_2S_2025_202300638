CC = gcc
FLEX = flex
BISON = bison
SRC = src
INC = include
BUILD = build

LEXER = $(SRC)/parser/lexer.l
PARSER = $(SRC)/parser/parser.y
MAIN = $(SRC)/main.c

# Archivos modulares de la UI
UI_DIR = $(SRC)/UI
UI_FILES = $(UI_DIR)/UI.c \
           $(UI_DIR)/menu.c \
           $(UI_DIR)/toolbar.c \
           $(UI_DIR)/editor.c \
           $(UI_DIR)/console.c \
           $(UI_DIR)/reports.c \
           $(UI_DIR)/styles.c \
           $(UI_DIR)/main_window.c

# Directorio de análisis semantico
PARSER_DIR = $(SRC)/parser/semantic
PARSER_FILES = $(PARSER_DIR)/semantic.c \
               $(PARSER_DIR)/execute.c \
               $(PARSER_DIR)/evaluate.c \
               $(PARSER_DIR)/utils.c \
               $(PARSER_DIR)/get_semantic_enums.c \
               $(PARSER_DIR)/casting_operations.c \
               $(PARSER_DIR)/comparative_operations.c \
               $(PARSER_DIR)/ListEvaluate.c \
               $(PARSER_DIR)/create_error.c

# Archivos modulares de estructuras

STRUCTURES_DIR = $(SRC)/structures
STRUCTURES_FILES = $(STRUCTURES_DIR)/Instruction.c \
                  $(STRUCTURES_DIR)/Errors.c \
                  $(STRUCTURES_DIR)/SymbolTable.c \
                  $(STRUCTURES_DIR)/If_Node.c \
                  $(STRUCTURES_DIR)/Switch_case.c \
                  $(STRUCTURES_DIR)/List.c \
                  $(STRUCTURES_DIR)/Expression_list.c \
                  $(STRUCTURES_DIR)/FuctionNode.c

REPORTS_DIR = $(SRC)/reports
STRUCTURES_FILES += $(REPORTS_DIR)/ast_generator.c \
                    $(REPORTS_DIR)/ast_execute.c \
                    $(REPORTS_DIR)/utils.c \
                    $(REPORTS_DIR)/ast_evaluate.c


GTK_FLAGS = `pkg-config --cflags --libs gtk+-3.0`

# Flags para silenciar advertencias de GTK
WARNINGS = -Wno-deprecated-declarations

all: $(BUILD)/parser.tab.c $(BUILD)/lexer.yy.c $(MAIN) $(UI_FILES) $(STRUCTURES_FILES) $(PARSER_FILES)
	$(CC) -I$(INC) -I$(UI_DIR) $(WARNINGS) $(BUILD)/parser.tab.c $(BUILD)/lexer.yy.c $(MAIN) $(UI_FILES) $(REPORTS_FILES) $(STRUCTURES_FILES) $(PARSER_FILES) -o $(BUILD)/main $(GTK_FLAGS) -luuid -lm

$(BUILD)/parser.tab.c $(BUILD)/parser.tab.h: $(PARSER)
	$(BISON) -d -o $(BUILD)/parser.tab.c $(PARSER)
	cp $(BUILD)/parser.tab.h $(INC)/parser.tab.h

$(BUILD)/lexer.yy.c: $(LEXER)
	$(FLEX) -o $(BUILD)/lexer.yy.c $(LEXER)

clean:
	rm -f $(BUILD)/*
