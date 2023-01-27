SRC_DIR := ./src
BUILD_DIR := ./build

PROBLEMS := $(shell find $(SRC_DIR) -name '*.c' | sed -E "s@^(\.\/)?src\/([^.\s]*)(\.c)@$(BUILD_DIR)/\2@g")

all: $(PROBLEMS)

.SECONDEXPANSION:
$(PROBLEMS): % : $$(subst build,src,%.c)
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<	

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)/
