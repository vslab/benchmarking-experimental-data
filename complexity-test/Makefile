REP=30
E1=cycles,instructions,cache-misses
E2=cache-references,branch-misses,branch-instructions
MAX=4192304
all: clean test
f:
	gcc -lm f.c -o f
g:
	gcc -lm g.c -o g
fg:
	gcc -lm fg.c -o fg
cpu:
	gcc cpu.c -o cpu
mem:
	gcc mem.c -o mem
clean:
	rm -f f g fg cpu mem
	rm log*
	rm machine.txt
.PHONY: clean
test: f g fg cpu mem
	for i in $$(seq 65536 65536 $(MAX)) ; do echo $$i ; done
	perf stat -x ',' -e cycles,instructions,cache-misses -o log.cpu -r $(REP) ./cpu
	perf stat -x ',' -e cache-references,branch-misses,branch-instructions -o log.cpu --append -r $(REP) ./cpu
	perf stat -x ',' -e cycles,instructions,cache-misses -o log.mem -r $(REP) ./mem
	perf stat -x ',' -e cache-references,branch-misses,branch-instructions -o log.mem --append -r $(REP) ./mem
	for i in $$(seq 65536 65536 $(MAX)) ; do perf stat -x ',' -e cycles,instructions,cache-misses -o log.f.$$i -r $(REP) ./f $$i ; done
	for i in $$(seq 65536 65536 $(MAX)) ; do perf stat -x ',' -e cache-references,branch-misses,branch-instructions -o log.f.$$i --append -r $(REP) ./f $$i ; done
	for i in $$(seq 65536 65536 $(MAX)) ; do perf stat -x ',' -e cycles,instructions,cache-misses -o log.g.$$i -r $(REP) ./g $$i ; done
	for i in $$(seq 65536 65536 $(MAX)) ; do perf stat -x ',' -e cache-references,branch-misses,branch-instructions -o log.g.$$i --append -r $(REP) ./g $$i ; done
	for i in $$(seq 65536 65536 $(MAX)) ; do perf stat -x ',' -e cycles,instructions,cache-misses -o log.fg.1.$$i -r $(REP) ./fg $$i 0 ; done
	for i in $$(seq 65536 65536 $(MAX)) ; do perf stat -x ',' -e cache-references,branch-misses,branch-instructions -o log.fg.1.$$i --append -r $(REP) ./fg $$i 0 ; done
	for i in $$(seq 65536 65536 $(MAX)) ; do perf stat -x ',' -e cycles,instructions,cache-misses -o log.fg.2.$$i -r $(REP) ./fg $$i 1 ; done
	for i in $$(seq 65536 65536 $(MAX)) ; do perf stat -x ',' -e cache-references,branch-misses,branch-instructions -o log.fg.2.$$i --append -r $(REP) ./fg $$i 1 ; done
	for i in $$(seq 65536 65536 $(MAX)) ; do perf stat -x ',' -e cycles,instructions,cache-misses -o log.fg.3.$$i -r $(REP) ./fg $$i 2 ; done
	for i in $$(seq 65536 65536 $(MAX)) ; do perf stat -x ',' -e cache-references,branch-misses,branch-instructions -o log.fg.3.$$i --append -r $(REP) ./fg $$i 2 ; done
	for i in $$(seq 65536 65536 $(MAX)) ; do perf stat -x ',' -e cycles,instructions,cache-misses -o log.fg.4.$$i -r $(REP) ./fg $$i 3 ; done
	for i in $$(seq 65536 65536 $(MAX)) ; do perf stat -x ',' -e cache-references,branch-misses,branch-instructions -o log.fg.4.$$i --append -r $(REP) ./fg $$i 3 ; done

	for i in $$(seq 0 1 20) ; do perf stat -x ',' -e $(E1) -o log.mem2.$$((2**$$i)) -r $(REP) ./mem $$((2**$$i)) ; done
	for i in $$(seq 0 1 20) ; do perf stat -x ',' -e $(E2) -o log.mem2.$$((2**$$i)) --append -r $(REP) ./mem $$((2**$$i)) ; done

	for file in 'log*' ; do sed '/^$$/ d' -i $$file ; sed '/^#/ d' -i $$file ; done
	lscpu >> machine.txt
	free >> machine.txt
