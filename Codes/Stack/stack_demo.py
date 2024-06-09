# using list

stack=[]

stack.append(80)
stack.append(70)
stack.append(60)
stack.append(50)
stack.append(40)
stack.append(30)
stack.append(20)
stack.append(10)

print(f"""Stack is : {stack}""")

# print(type(stack))

print(f'''Top element is : {stack[-1]}''')

print(f'Poppoed element is: {stack.pop()}')

print(f"""Stack is : {stack}""")