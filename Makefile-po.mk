# This requires at least cadius v 1.3.0 (https://github.com/mach-kernel/cadius/releases;
# Tested with cadius v 1.4.5) - support for file's type and auxtype via the filename needed.
PO = $(NAME).po

CA ?= cadius

# Unix or Windows
ifeq ($(shell echo),)
	CP = cp $1
	MV = mv
	RM = rm
else
	CP = copy $(subst /,\,$1)
	MV = ren
	RM = del
endif

REMOVES += $(PO)

.PHONY: po
po: $(PO)

$(NAME).system:
	cp $(NAME).apple2.loader $(NAME).system#FF2000

$(PO): $(NAME).apple2 $(NAME).system
	$(call CP, apple2/template.po $@)
	$(MV) $(NAME).apple2 $(NAME)#064000
	$(CA) addfile $(NAME).po /mminer $(NAME).system#FF2000
	$(CA) addfile $(NAME).po /mminer $(NAME)#064000
	$(RM) $(NAME).system#FF2000
	$(RM) $(NAME)#064000