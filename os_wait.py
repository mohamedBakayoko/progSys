import os

pid = os.fork()

if pid:
	status = os.wait()
	print("\n Dans le processus parent")
	print("Terminated child's process id:", os.getpid(), os.getppid())
else:
	print("______Dans le processus fils______")
	print("\n\tProcess ID:", os.getpid(), os.getppid())

