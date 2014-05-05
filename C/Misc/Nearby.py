#!/usr/bin/python

import sys
        
def getSize():
    try:
        line = raw_input()
    except IOError:
        print "Error accepting buffer size."
        sys.exit()

    line = line.split()
    try:
        isinstance(line[0], int)
        isinstance(line[1], int)
        isinstance(line[2], int)
    except ValueError:
        print "Error in value of size."
        sys.exit()

    return [int(line[0]), int(line[1]), int(line[2])]

def getTopics(T, topics):
    i = 0
    while(i < T):
        try:
            line = raw_input()
        except IOError:
            print "Error accepting word."
            sys.exit()

        line = line.split()

        try:
            isinstance(line[0], int) and int(line[0]) < T
            isinstance(line[1], float)
            isinstance(line[2], float)
        except ValueError:
            print "Error in value of size."
            sys.exit()
              
        topics[int(line[0])] = [float(line[1]), float(line[2])]
        i = i + 1

def getQuestions(T, Q, topicToQues):
    i = 0
    while(i < Q):
        try:
            line = raw_input()
        except IOError:
            print "Error accepting word."
            sys.exit()

        line = line.split()

        try:
            isinstance(line[0], int) and int(line[0]) < Q
            isinstance(line[1], int)
        except ValueError:
            print "Error in value of size."
            sys.exit()

        for j in range(int(line[1])):
            try:
                isinstance(line[2+j], int) and int(line[2+j]) < T
            except ValueError:
                print "Error in value of size."
                sys.exit()

            topic = int(line[2+j])
            ques = []
            if (topicToQues.has_key(topic)):
                ques = topicToQues[topic]
            else:
                ques = []
            ques.append(int(line[0]))
            topicToQues[topic] = list(set(ques))

        i = i + 1

def getDistance(X,Y,x,y):
    return ((X-x)**2 + (Y-y)**2)**(0.5)

def getClosestTopics(topics, X, Y, num):
    closestTopics = []
    index = 0
    for key, [tx,ty] in topics.items():
        distance = getDistance(X,Y,tx,ty)
        if(index < num):
            closestTopics.append(tuple([key, distance]))
            index = index + 1
            if (index == num):
                closestTopics = sorted(closestTopics, key=lambda x: x[1])
        else:
            [_, lastDistance] = list(closestTopics[index-1])
            if (lastDistance > distance):
                closestTopics[index-1] = tuple([key, distance])
                closestTopics = sorted(closestTopics, key=lambda x: x[1])

    return closestTopics

def getQueries(N, topics, topicToQues):
    i = 0
    while(i < N):
        try:
            line = raw_input()
        except IOError:
            print "Error accepting word."
            sys.exit()

        line = line.split()

        try:
            line[0] == 't' or line[0] == 'q'
            isinstance(line[1], int)
            isinstance(line[2], float)
            isinstance(line[3], float)
        except ValueError:
            print "Error in value of size."
            sys.exit()

        num = int(line[1])
        X = float(line[2])
        Y = float(line[3])

        closestTopics = getClosestTopics(topics, X, Y, num)
        closestTopics.sort(key=lambda x: x[1])
        #closestTopics.sort(key=lambda x: x[0], reverse=True)

        printStr = ""
        if (line[0] == 't'):
            for topic,_ in closestTopics:
                printStr = printStr+str(topic)+" "
        elif (line[0] == 'q'):
            qs = []
            for topic,_ in closestTopics:
                questions = topicToQues[topic]
                questions = reversed(sorted(questions))
                for ques in questions:
                    if (ques not in qs) and (num):
                        printStr = printStr+str(ques)+" "
                        qs.append(ques)
                        num = num - 1
        print printStr

        i = i + 1

def main():
    [T, Q, N] = getSize()
    topics = {}
    getTopics(T, topics)
    topicToQues = {}
    getQuestions(T, Q, topicToQues)
    getQueries(N, topics, topicToQues)

# If called from the command line, invoke main()
if __name__ == "__main__":
    main()
