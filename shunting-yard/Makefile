TARGET = $(notdir $(CURDIR))
SOURCES = $(wildcard [^_]*.c)
OBJECTS = $(SOURCES:%.c=%.o)
DEPENDENCIES = $(SOURCES:%.c=%.d)

# Заставляет компиятор создавать файлы *.d с зависимостями
# для каждого модуля. Такие файлы содержат список заголовков
# *.h и имеют синтакис, подходящий для импрота в этот файл
CFLAGS += -MMD

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(DEPENDENCIES) $(TARGET)

run: $(TARGET)
	./$(TARGET)

-include $(DEPENDENCIES)
