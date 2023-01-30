SRC_DIR := ./src
BUILD_DIR := ./build

# Doesn't work with non *nix
PROBLEMS := $(shell find $(SRC_DIR) -name '*.c' | sed -E "s@^(\.\/)?src\/([^.\s]*)(\.c)@$(BUILD_DIR)/\2@g")
# Equivalent expansion
# PROBLEMS := build/problem1 build/problem2 ...

all: $(PROBLEMS)

.SECONDEXPANSION:
$(PROBLEMS): % : $$(subst build,src,%.c)
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<	

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)/
