from sqlalchemy import *
from sqlalchemy.sql import *

engine = create_engine('sqlite:///:memory:', echo=True)  #mettre ma base.db ici 

metadata = MetaData()                                     

users = Table('users', metadata,                          
            Column('id', Integer, autoincrement=True, primary_key=True),
            Column('name', String))

emails = Table('emails', metadata,
            Column('id', Integer, autoincrement=True, primary_key=True),
            Column('uid', None, ForeignKey('users.id')),
            Column('email', String, nullable=False))

metadata.create_all(engine)                               
connection = engine.connect()                             

u_ins = users.insert()

connection.execute(u_ins.values(name='Julien'))
connection.execute(u_ins.values(name='Mr Bean'))

connection.execute(emails.insert(), [
    {'uid': 1, 'email': 'julien.ponge@insa-lyon.fr'},
    {'uid': 1, 'email': 'julien.ponge@inria.fr'},
    {'uid': 2, 'email': 'mrbean@outlook.com'}
])


for row in connection.execute("select * from users"):
    print(row)
print('\n')

for row in connection.execute('select * from users where (name like ?) or (id > ?)', 'J%', 1):
    print(row)
print('\n')

for row in connection.execute(select([users, emails])):
    print(row)
    print(row[users.c.name])
    print("%s ^^ %s" % (row[0], row[1]))
print('\n')

for row in connection.execute(select([users.c.name, emails.c.email])):
    print(row)
print('\n')

s = select([users.c.name, emails.c.email]).where(users.c.id == emails.c.uid)
for row in connection.execute(s):
    print(row)
print('\n')

s = select([users.c.name, func.count(users.c.id)]).\
        where(users.c.id == emails.c.uid).\
        group_by(users.c.id)
for row in connection.execute(s):
    print(row)
print('\n')

s = select([users.c.name]).\
        where(
            and_(
                users.c.id == emails.c.uid,
                emails.c.email.like('%@outlook.com')
            )
        )
for row in connection.execute(s):
    print(row)
print('\n')

s = text('SELECT users.name FROM users WHERE users.name LIKE :x')
for row in connection.execute(s, x='julien%'):
    print(row)
print('\n')                                               

connection.close() 