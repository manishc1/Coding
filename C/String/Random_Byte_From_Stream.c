/*
You have a stream of bytes from which you can read one byte at a time. You only have enough space to store one byte. After processing those bytes, you have to return a random byte. Note: The probability of picking any one of those bytes should be equal.
*/

public static int getRan(Node m)
	{
		int range=1;
		Random random=new Random();
		int ret=(Integer)m.getValue();
		while(m.next!=null)
		{
			m=m.next;
			range++;
			if(random.nextInt(range)==0)
			{
				ret=(Integer)m.getValue();
			}
		}
		return ret;
	}
