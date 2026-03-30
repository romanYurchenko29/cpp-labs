#   make format
#   make check
#   make all 
#   make help

CC_FILES := $(wildcard *.c)
HH_FILES := $(wildcard *.h)
ALL_FILES := $(CC_FILES) $(HH_FILES)

ifeq ($(ALL_FILES),)
  $(error no .c or .h files)
endif

.PHONY: all format check help

format:
	@echo "Форматирование файлов: $(ALL_FILES)"
	@clang-format -i -style="{BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 110}" $(ALL_FILES)
	@echo "Форматирование завершено."

check:
	@echo "Запуск cppcheck для файлов: $(ALL_FILES)"
	@cppcheck --enable=warning,performance,portability,style --std=c11 \
	          --quiet $(ALL_FILES) || echo " cppcheck завершился с предупреждениями"
	@echo "Проверка кода завершена."

help:
	@echo "Доступные команды:"
	@echo "  make format    — отформатировать все .c/.h файлы в src/"
	@echo "  make check     — запустить cppcheck"
	@echo "  make all       — форматировать + проверить"
	@echo "  make help      — показать это сообщение"