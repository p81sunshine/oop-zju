import pickle

# 定义一个对象
# data = {'name': 'Alice', 'age': 30, 'married': True}
data = [1,2,3]


# 序列化对象为二进制格式
serialized_data = pickle.dumps(data)

# 可以将二进制数据存储到文件中
with open('data.bin', 'wb') as f:
    f.write(serialized_data)

# 反序列化二进制数据为对象
deserialized_data = pickle.loads(serialized_data)

# 打印反序列化后的对象
print(deserialized_data)
