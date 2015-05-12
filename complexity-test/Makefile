REP:=3
all: clean test
f:
	gcc -lm f.c -o f
g:
	gcc -lm g.c -o g
fg:
	gcc -lm fg.c -o fg
clean:
	rm -f f g fg
	rm log*
.PHONY: clean
test: f g fg
	for i in $$(seq 65536 65536 1048576) ; do perf stat -x ',' -e cycles,instructions,cache-misses -o log.f.$$i -r $(REP) ./f $$i ; done
	for i in $$(seq 65536 65536 1048576) ; do perf stat -x ',' -e cache-references,branch-misses,branch-instructions -o log.f.$$i --append -r $(REP) ./f $$i ; done
	for i in $$(seq 65536 65536 1048576) ; do perf stat -x ',' -e cycles,instructions,cache-misses -o log.g.$$i -r $(REP) ./g $$i ; done
	for i in $$(seq 65536 65536 1048576) ; do perf stat -x ',' -e cache-references,branch-misses,branch-instructions -o log.g.$$i --append -r $(REP) ./g $$i ; done
	for i in $$(seq 65536 65536 1048576) ; do perf stat -x ',' -e cycles,instructions,cache-misses -o log.fg.1.$$i -r $(REP) ./fg $$i 0 ; done
	for i in $$(seq 65536 65536 1048576) ; do perf stat -x ',' -e cache-references,branch-misses,branch-instructions -o log.fg.1.$$i --append -r $(REP) ./fg $$i 0 ; done
	for i in $$(seq 65536 65536 1048576) ; do perf stat -x ',' -e cycles,instructions,cache-misses -o log.fg.2.$$i -r $(REP) ./fg $$i 0 ; done
	for i in $$(seq 65536 65536 1048576) ; do perf stat -x ',' -e cache-references,branch-misses,branch-instructions -o log.fg.2.$$i --append -r $(REP) ./fg $$i 0 ; done
	for i in $$(seq 65536 65536 1048576) ; do perf stat -x ',' -e cycles,instructions,cache-misses -o log.fg.3.$$i -r $(REP) ./fg $$i 0 ; done
	for i in $$(seq 65536 65536 1048576) ; do perf stat -x ',' -e cache-references,branch-misses,branch-instructions -o log.fg.3.$$i --append -r $(REP) ./fg $$i 0 ; done
	for file in 'log*' ; do sed '/^$$/ d' -i $$file ; sed '/^#/ d' -i $$file ; done
