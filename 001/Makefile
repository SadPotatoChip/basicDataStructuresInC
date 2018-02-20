prog: listz.h treez.h stackqueue.h 1.c	
	gcc -o prog listz.c treez.c stackqueue.c 1.c
	
listz.h: listz.c nodeDef.c
	./ctoh listz.c nodeDef.c

treez.h: treez.c nodeDefTree.c
	./ctoh treez.c nodeDefTree.c

stackqueue.h: stackqueue.c stackqueueDef.c
	./ctoh stackqueue.c stackqueueDef.c