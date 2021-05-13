class Student:
    def __init__(self, x, y):  # CONSTRUCTOR INITIALIZES OBJECT
        self.id = x
        self.name = y          # INSTANCE VARIABLES
        self.classes = []

    def add_class(self, x):          # METHODS
        self.classes.append(x)

    def drop_class(self, x):
        self.classes.remove(x)

    def show_classes(self):
        print(" ".join(self.classes))

    def __str__(self):  # return a str
        return f"Student({self.id}, {self.name})"

    def __len__(self):  # return an int
        return 192

    def __add__(self, other):  # some Student object + other
        return Student(0, "asd")

    def __lt__(self, other):
        return 123


    # def __radd__(self, other):   # other + some Student object
    #     return 0

if __name__ == "__main__":
    s1 = Student(10, "Henry")
    s2 = Student(23, "Dathan")

    print(type(s1) == type(s2))  # THEY HAVE THE SAME TYPE
    print(s1.id, s2.id)          # THEY HAVE DIFFERENT IDS
    s1.add_class("bio")
    s1.add_class("cs")
    s1.add_class("akushdqiuwh")
    s1.show_classes()
    s2.show_classes()

    print(Student(0, "asd").name)
    # print(type(x))
    # print(x.id)
    # print(x.name)


    # s1.__add__(812764)
