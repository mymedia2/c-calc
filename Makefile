.PHONY: all clean run

all clean:
	$(MAKE) $@ -C shunting-yard
	$(MAKE) $@ -C reverse-polish

run: all
	echo -n '> '; ./shunting-yard/shunting-yard -n | ./reverse-polish/reverse-polish -n
