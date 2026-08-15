###############################################################################
### The one-screen (non-scrolling) build of the game                        ###
###############################################################################

# src/apple2.noscroll holds a second, complete build of the game whose artwork
# is crunched 2:1 horizontally so a whole level fits the screen and no scrolling
# is needed. It is laid out exactly like src/apple2 and uses its own copy of the
# same linker config, so it loads at $4000 and starts at $6000 just like mminer
# does - the only thing that differs is the file name, which is what the loader
# in src/apple2.loader switches on. So the generic rules can build it the way
# they build mminer, just with another target variant and another program name,
# which is what the recursive make below is for.

NOSCROLL_NAME   := ominer
NOSCROLL_TARGET := apple2.noscroll
NOSCROLL        := $(NOSCROLL_NAME).$(NOSCROLL_TARGET)
NOSCROLL_MAKE    = $(MAKE) TARGETS=$(NOSCROLL_TARGET) PROGRAM=$(NOSCROLL_NAME)

# Inside the recursive make this file gets included again - and there $(NOSCROLL)
# is the generic $(PROGRAM) - so keep these targets out of it to make recursing
# into ourselves impossible.
ifneq ($(TARGETS),$(NOSCROLL_TARGET))

.PHONY: noscroll noscroll-clean

noscroll:
	$(NOSCROLL_MAKE) all

noscroll-clean:
	$(NOSCROLL_MAKE) clean

# Hook into the top level make only. A recursive make builds and cleans just its
# own variant, so if it picked up the hooks of the other variants too they would
# keep calling each other for ever.
ifeq ($(MAKELEVEL),0)
all: noscroll
clean zap: noscroll-clean
endif

endif
