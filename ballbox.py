'''
# =============================================================================
#      FileName: ballbox.py
#          Desc: 
#        Author: LiChenda
#         Email: lichenda1996@gmail.com
#      HomePage: https://github.com/LiChenda
#       Version: 0.0.1
#    LastChange: 2016-05-16 20:31:56
#       History:
# =============================================================================
'''

balls = []
stepl = 0.1

def putball():
    ball = {'x':-1 + stepl, 'y': -1 + stepl, 'r':stepl}
    ballMax = {'x': ball['x'], 'y': ball['y'], 'r':stepl}
    R2 = 0.0;
    for i in range(int(2 / stepl)):
        ball['x'] += stepl;
        ball['y'] = -1 + stepl;
        for j in range(int(2 / stepl)):
            ball['y'] += stepl;
            ball['r'] = 0;
            flag = False;
            while jude(ball):
                flag = True;
                ball['r'] += stepl

            if flag and ((ball['r'] - stepl) > ballMax['r']):
                ballMax['r'] = ball['r'] - stepl
                ballMax['x'] = ball['x']
                ballMax['y'] = ball['y']
    print(jude(ballMax, True))

    balls.append(ballMax);



def distance(b1, b2):
    return ((b1['x'] - b2['x'])**2 + (b1['y'] - b2['y'])**2)**0.5

def jude(b, x = False):
    if ((abs(b['x']) + b['r'] > 1 )or (abs(b['y']) + b['r']) > 1):
        return False;
    if(x):
        print(balls)

    flag = True
    for ball in balls:
        if(ball['r']+ b['r'] > distance(b, ball)):
            flag = False

    return flag



n = input()
R2 = 0;


for i in range(int(n)):
    putball()
    pass

for ball in balls:
    R2 += ball['r']**2
    pass
print(balls)

print(R2)



