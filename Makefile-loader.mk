###############################################################################
### The ProDOS 8 loader that goes on the disk as MMINER.SYSTEM               ###
###############################################################################

# src/apple2.loader is another target variant, built the same way the game is -
# see Makefile-noscroll.mk for how that works. It has no program name of its own
# because the disk images want it named after the game: ProDOS runs it as
# MMINER.SYSTEM and it derives the name of the game binary from its own pathname.

LOADER_TARGET := apple2.loader
LOADER        := $(NAME).$(LOADER_TARGET)
LOADER_MAKE    = $(MAKE) TARGETS=$(LOADER_TARGET)

ifneq ($(TARGETS),$(LOADER_TARGET))

.PHONY: loader loader-clean

loader:
	$(LOADER_MAKE) all

loader-clean:
	$(LOADER_MAKE) clean

# Top level only - see the comment on the same hooks in Makefile-noscroll.mk.
ifeq ($(MAKELEVEL),0)
all: loader
clean zap: loader-clean
endif

endif
