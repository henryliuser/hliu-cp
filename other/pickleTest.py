import pickle
class Foo:
    attr = 'A class attribute'

picklestring = pickle.dumps(Foo)
print(picklestring)
