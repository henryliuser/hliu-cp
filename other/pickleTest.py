import pickle, platform
class Foo:
    attr = 'A class attribute'

picklestring = pickle.dumps(Foo)
print(picklestring)
print(platform.python_implementation())
