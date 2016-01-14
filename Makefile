all: cminor exec 

parser.tab.c parser.tab.h parser.output: parser.y
	bison -d -bparser -v parser.y

scanner.c: scanner.l parser.tab.h
	flex --noyywrap -o scanner.c scanner.l

%.o: %.c *.h
	gcc -c $< -o $@ -g

cminor: parser.tab.o scanner.o main.o token.o stmt.o decl.o expr.o type.o param_list.o symbol.o hash_table.o scope.o register.o
	gcc parser.tab.o scanner.o main.o token.o stmt.o decl.o expr.o type.o param_list.o symbol.o hash_table.o scope.o register.o -g -o cminor

out.s:
	./cminor -codegen test2.cminor out.s

exec:	out.s library.o
	gcc out.s library.o -o exec

.PHONY: clean

clean:
	rm *~ parser.tab.* parser.output cminor *.o scanner.c *.cminor.out *.s exec
