import pickle, platform
class Foo:
    attr = 'A class attribute'

picklestring = pickle.dumps(Foo)
print(picklestring)
print(platform.python_implementation())

a, *b, c = range(10)
print(a, b, c)
