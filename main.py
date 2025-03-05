# main.py
import hello_func
import hello_class

hello_func.hello_world()

hello_instance = hello_class.Hello("Alice")
hello_instance.hello()
hello_class.Hello.hello_world()
