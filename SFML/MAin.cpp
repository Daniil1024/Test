#include <SFML/Graphics.hpp> //����������� ����������� ����������
#include <iostream> 
#include <sstream>

using namespace sf;
using namespace std; 

RenderWindow window(sf::VideoMode(800, 600), L"������������ �������");//������������� ����
Font font;//�������� ������� ������
Sprite load;//�������� ������ � ����
int level;
int alphabet(char ch, char alphabet[])//������ char �� ����� ������� � Keyboard
        {
 

            //������ ���� ���������� ����
            for (int ii = 0;ii<25;ii++)//���� ���� ���������� ����� ����� � ��������
            {
                if (char(ch) == alphabet[ii]){return ii;}
            }
 
 
     }


void array(char *m) //������������� ������� ��������
{
	for (int i = 'a', j = 0; i <= 'z'; i++, j++) { //���� ��������� ������ �������
		m[j] = char(i); 
	} 
} 

String random_string(int lvl, char *m) //����� ��� ��������� ��������� ������
{ 
 string str;
 window.clear();
	srand(time(NULL));
	for (int j = 0,s; j < 25; j++) 
	{ 
		s = rand() % (lvl+1); //����� ��������� ����� � ����������� �� ������
		char c = m[s];
		if(c == ' ')//���� �������������� ������ ���������� ������ ��� �� �����
		{
		 j--;
		}
		else{//����� �������� ����� � ������
		str += c;
		}
	}
	return str;
} 

int menu(int key[] ) //���� � ����� ������ ����� ���� ��� �������� ������
{ 
	int number = 1;//���������� ��� �������� ���������� ����� ������������(number)
	Text text("", font, 20);//������������� ��������� ������ � ������ ������� � ��������
	text.setColor(Color :: White);
	text.setPosition(110 , 200);
	text.setString("\n\n\n�������� ������ �� ����������� '������������ ��������'\n                      ������� '������' ��� ������ ����");
	 window.clear();   // _
	 window.draw(load);//  |_��������� ������� � ������
window.draw(text);     //  |
window.display();    //   -

while(true){//���� ������� ������� �������
 Event event;
			 while (window.pollEvent(event))//���� �������������� �������
	  {
	   if (event.type == sf::Event::Closed){//���� ���� �����������
window.close();
exit(0);
	   }
	  }
 if(Keyboard :: isKeyPressed(Keyboard :: Space))//���� ���������� ������ �� ������� �� �����
	 break;
	}
	while (true) //����� ������ ����� ���� ��� �������� ������
{ 
	{
	 text.setPosition(270 , 230);
	 text.setString("\n            �������:\n\"1\" ��� ������ ����� ����\n\"2\" ��� �������� ������\n\"Esc\" ��� ������ �� ����"); 
	 window.clear();
	 window.draw(load);
window.draw(text);
window.display();
while(true){
 Event event;
			 while (window.pollEvent(event))
	  {
	   if (event.type == sf::Event::Closed){
window.close();
exit(0);
	   }
	  }
 if(Keyboard :: isKeyPressed(Keyboard :: Num1)){//���� ������ "1"
 number = 1;
 break;}
if(Keyboard :: isKeyPressed(Keyboard :: Num2)){//���� ������ "2"
 while(true){
  if(!Keyboard :: isKeyPressed(Keyboard :: Num2))
  {
   break;
  }
 
 }
 number = 2;
 break;}
if(Keyboard :: isKeyPressed(Keyboard :: Escape)){//���� ������ "Esc"
exit(0);
break;
}
}
		if (number == 1) //���� ������������ ����� 1
		{ 
		 text.setPosition(140 , 200);
		 text.setString("\n                     �� ������ ������ ����� ����\n          ������� ������, ������� ������� �� ������\n         �� ���������� ������ ��� ������ 10 ������\n�� ������ ����� ��������� ����� ������������ 0,1 ���\n                    � ��������� ������ ����������\n                  ��� ������ ���� ������� \"������\""); 
		 window.clear();
		 window.draw(load);
window.draw(text);
window.display();
		 while (true){
		  Event event;
			 while (window.pollEvent(event))
	  {
	   if (event.type == sf::Event::Closed){
window.close();
exit(0);
	   }
	  }
		  if(Keyboard :: isKeyPressed(Keyboard :: Space))//���� ����� ������
		   while(true)
		   {
			Event event;
			 while (window.pollEvent(event))
	  {
	   if (event.type == sf::Event::Closed){
window.close();
exit(0);
	   }
	  }
			if(!Keyboard :: isKeyPressed(Keyboard :: Space))
			return 1; 
		   }
		} 
		}
		if (number == 2)  //���� ������������ ����� 2
		{ 
	    	  text.setPosition(230 , 250);
		      
			  int cheat = 0;//�������� ����
			  int beginning = 0;//���� ��� ���������� ������� �������, ��� ���������� ������
			       bool flag = false;//������� ����
			       while(true)//���� ����
			       {
					   if(flag)
						   break;
					   Event ev;
					   while(window.pollEvent(ev))
					   {
						if(beginning > 0){
					    	if(ev.type == Event :: KeyPressed && cheat/1000<1)//���� ������ �������
					    	{

								   if(ev.key.code == Keyboard :: Num0)//���������, ����� ������(switch �� ����������� ��-�� ����� � ���)
								   {
									   cheat = cheat*10+0;//"�����������" ������ � ����� �����								
								   }
								   if(ev.key.code == Keyboard :: Num1)
								   {
									   cheat = cheat*10+1;								
								   }
								   if(ev.key.code == Keyboard ::Num2)
								   {
									   cheat = cheat*10+2;								
								   }
								   if(ev.key.code == Keyboard ::Num3)
								   {
									   cheat = cheat*10+3;								
								   }
								   if(ev.key.code == Keyboard ::Num4)
								   {
									   cheat = cheat*10+4;
								   }
								   if(ev.key.code == Keyboard ::Num5)
								   {
									   cheat = cheat*10+5;
								   }
								   if(ev.key.code == Keyboard ::Num6)
								   {
									   cheat = cheat*10+6;								
								   }
								   if(ev.key.code == Keyboard ::Num7)
								   {
									   cheat = cheat*10+7;									
								   }
								   if(ev.key.code == Keyboard ::Num8)
								   {
									   cheat = cheat*10+8;									
								   }
								   if(ev.key.code == Keyboard ::Num9)
								   {
									   cheat = cheat*10+9;								
								   }
								   
					    	}
							if(ev.type == Event :: KeyPressed)
							{
							 if(ev.key.code == Keyboard :: BackSpace)
								   {
									   cheat = cheat/10;//"�������" ���� ����� ������									
								   }
								   if(ev.key.code == Keyboard :: Return)//���� ����� Enter, �. �. ������������ ���������� ����
								   {
									flag = true;
									break;
								   }
							}
						}
						else{beginning++;}
					   }
					   ostringstream str;
					   str << cheat;
					   if(cheat != 0){//���� ������������ ������ �� ������ �� ��� �� ������������
					   text.setString("\n�� ������� ����� \"��������� �������\"\n������� ���� ���������������� ������:" + str.str());
					   }
					   else{
					   text.setString("\n�� ������� ����� \"��������� �������\"\n������� ���� ���������������� ������:"); 
					   }
	          window.clear();
			  window.draw(load);
              window.draw(text);
              window.display();
			       }
			  for (int i = 0; i < 25; i++) 
			  { 
			    	if (cheat == key[i]) //���� ��� ������
			     	{
				       std::ostringstream str;
	                   str << (i+1);	
		               text.setPosition(250, 230);
		               text.setString("\n\n        �� ������� " + str.str() +" �������\n ��� ������ ���� ������� \"������\"");
					   window.clear();
					   window.draw(load);
                       window.draw(text);
                       window.display();
	             	   while(true)
		               {
						   Event event;
		                   while (window.pollEvent(event))
	                       {
	                           if (event.type == sf::Event::Closed){
                                   window.close();
                                   exit(0);
	                           }
	                       }
		                   if(Keyboard :: isKeyPressed(Keyboard :: Space))//���� ����� ������ ����� �� ����� ����� ����
		                       break;
		               }
					   return i + 1; 
				   } 
			    }
			    text.setString("\n���������� ���� ����� �� ����������\n������� \"Esc\" ��� ������ � ������� ����"); 
		        window.clear();
				window.draw(load);
                window.draw(text);
                window.display();
                while(true)
                {
                    if(Keyboard :: isKeyPressed(Keyboard :: Escape))//���� ������ "Esc" ����� �� �����
					{
					 while(true){
					  if(!Keyboard :: isKeyPressed(Keyboard :: Escape))
					 break;
					 }
					 break;
					}
                }  
	    } 
	}
}
}
int main(){
    Texture t;
    t.loadFromFile("fon.jpg");//������������� ��������
	load.setTexture(t);//�������� �������� � ������
    load.setTextureRect(IntRect(0, 0, 800, 600));
	load.setPosition(0,0);
    Font localFont;//�������� ���������� ������
	localFont.loadFromFile("Font.ttf");//�������� ������ �� �����
	font = localFont;
	
	//������ � ������
	int key[] = { 1320, 5051, 3299, 9488, 2620, 4744, 6164, 2405, 8821, 2275, 1030, 9325, 9094, 2243, 9572, 5847, 5741, 1509, 6272, 5109, 4976, 6393, 5477, 2904, 5817 };
	
	float time = 10;//���������� ���������� �� ���������� �����
	int right = 0, nright = 0;//���������� ���������� �� ��� - �� ��������� � ����������� ��������� ����
	char mass[28];//���������� - ���-�� ��������� �������� ����, ����������� � ������ � ���������
	level = menu(key);//����� ������
    while (window.isOpen()){//���� ���� �������
        Event locevent;
        while (window.pollEvent(locevent))
	    {
		    if (locevent.type == sf::Event::Closed)
			 window.close();
	    }
	    window.clear();
        window.draw(load);
        window.display();
        t.loadFromFile("Load.jpg");//�������� �������� �� �����
        load.setTexture(t);
        load.setPosition(50, 500);
        array(mass);//������������� ��������
		//������������� ����������
		right = 0; 
		nright = 0; 
		time = 10;
        std::ostringstream str;
		str << level;		
		Text leveltext("", font, 30);
		leveltext.setPosition(300 , 0);
		leveltext.setColor(Color :: White);

		char c;
		String string = random_string(level, mass);
		Sprite spr;
		int isRight[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//������ ��� �������� ������������ ����� ��� ������ �����
		Clock clock;//������ "����" ��� ��������� ���������� �������
	    clock.restart();
			for (int j = 0; j < 25; j+= 0)//���� �� ���� ������
			{
			    Texture texture;
				texture.loadFromFile("arrow.png");
				Sprite fon;
				Texture fonTexture;
				fonTexture.loadFromFile("fon1.jpg");
				fon.setTexture(fonTexture);
				spr.setTexture(texture);
				spr.setPosition(100+24*j, 60);
				load.setTextureRect(IntRect(0, 0, 600/10*(time), 33));//"�������������" �������� � ���������� ��������
			    c = string[j];
			    window.clear();
    			window.draw(fon);
				leveltext.setString("\n������� " + str.str() + "\n");
			    window.draw(leveltext);
				for(int i = 0; i < 25; i++)//���� ����������� ��� ����������� ����
				{
				    Texture rect;
				    Sprite s;
				    if(isRight[i] == 1){
				        rect.loadFromFile("green.jpg");
				    }
				    if(isRight[i] == 2)
				    {
				        rect.loadFromFile("red.jpg");
				    }
				    s.setPosition(100 + 24*i, 90);
				    s.setTexture(rect);
				    Text chartext(string[i], font, 30);
				    chartext.setPosition(100 + 24*i, 80);
				    chartext.setColor(Color :: White);
				    window.draw(s);
				    window.draw(chartext);
				}
				ostringstream strtime;
				strtime << int(time*10)/10.0;
			    Text ttime("���������� ����� "+strtime.str(),font,20);
				ttime.setPosition(50, 450);
				window.draw(load);
				window.draw(ttime);
				window.draw(spr);
				window.draw(leveltext);
				window.display();
				time -= clock.getElapsedTime().asSeconds();
				clock.restart();

                Event event;
			    while (window.pollEvent(event))
	            {
	                Texture texture;
				    texture.loadFromFile("arrow.png");
				    Sprite fon;
				    Texture fonTexture;
			   	    fonTexture.loadFromFile("fon1.jpg");
				    fon.setTexture(fonTexture);
				    spr.setTexture(texture);
				    spr.setPosition(100+24*j, 60);
				    window.clear();
				    window.draw(fon);
				    for(int i = 0; i < 25; i++)
				    {
				        Texture rect;
				        Sprite s;
				        if(isRight[i] == 1){
				            rect.loadFromFile("green.jpg");
				        }
				        if(isRight[i] == 2)
				        {
				            rect.loadFromFile("red.jpg");
				        }
				        s.setPosition(100 + 24*i, 90);
				        s.setTexture(rect);
				        Text chartext(string[i], font, 30);
				        chartext.setPosition(100 + 24*i, 80);
				        chartext.setColor(Color :: White);
				        window.draw(s);
				        window.draw(chartext);
					}
				    Text ttime("���������� ����� "+strtime.str(),font,20);
				    ttime.setPosition(50, 450);
				    window.draw(load);
				    window.draw(ttime);
				    window.draw(spr);
				    window.draw(leveltext);
				    window.display();


	                if (event.type == sf::Event::KeyPressed)//���� ������ �������(�����)
	                {
				       if(event.key.code == Keyboard :: Key(alphabet(c, mass)))//���� ����������
			           {
			               isRight[j] = 1;//� ������� ����� � ��������, ��������������� ����������� ������ ���������� �����, ������������� 1
			               j++;//��������� � ��������� �����
					       right++;//��������� 1 � ���������� ������
					       while(true)//���� ������� �������
					       {
					           if(!Keyboard :: isKeyPressed(Keyboard :: Key(alphabet(c, mass))))
						       {
					               time += 0.1;//������������ �����
					               break;
					           }
					       }				
					       break;
					   }
					   else //���� ������������
				       { 
				           isRight[j] = 2;//� ������� ����� � ��������, ��������������� ����������� ������ ���������� �����, ������������� 2
				           time -= 0.1;//���������� �����
					       j++;//��������� � ��������� �����
					       printf("\a");//������ ���� ������
					       nright++; //��������� 1 � ������������ ������
				       }
	               }
	               if (event.type == sf::Event::Closed)
				   {
                       window.close();
                       exit(0);
	               }
	          }
              if(time < 0){j = 24; break;}//���� ����� �����������, ����� �� �����
			  if (nright >= 5){ j=24;break; }//���� ������� ����� ������, ����� �� �����
	      }
		  if (nright >= 5)//���� ������� ����� ������
		  { 
		      Texture texture;
			  texture.loadFromFile("flag.png");
			  spr.setTexture(texture);
			  Sprite fon;
			  Texture fonTexture;
			  fonTexture.loadFromFile("fon1.jpg");
			  fon.setTexture(fonTexture);
			  ostringstream str;
			  str << key[level-1];
			  Text text("", font, 30);
			  text.setColor(Color :: White);
			  text.setPosition(100, 200);
			  text.setString("�� ������� ������� ����� ������  - 5 ��!\n         ���� �� ������ ������ ���: " + str.str() + "\n������� Esc ��� ������ � ������� ����"); 
			  window.draw(fon);
			  window.draw(leveltext);
			  for(int i = 0; i < 25; i++)
			  {
			      Texture rect;
				  Sprite s;
				  if(isRight[i] == 1){
				      rect.loadFromFile("green.jpg");
				  }
				  if(isRight[i] == 2)
				  {
				      rect.loadFromFile("red.jpg");
				  }
				  s.setPosition(100 + 24*i, 90);
				  s.setTexture(rect);
				  Text chartext(string[i], font, 30);
				  chartext.setPosition(100 + 24*i, 80);
				  chartext.setColor(Color :: White);
				  window.draw(s);
				  window.draw(chartext);
			  }
		      ostringstream strtime;
		 	  strtime << int(time*10)/10.0;//���������� ������� �� �������
		 	  Text ttime("���������� ����� "+strtime.str(),font,20);
			  ttime.setPosition(50, 450);
			  window.draw(load);
			  window.draw(ttime);
			  window.draw(spr);
			  window.draw(leveltext);
	          window.draw(text);
              window.display();			
			  while (true)
			  {
	              if(Keyboard :: isKeyPressed(Keyboard :: Escape))//���� ����� Ecs
			 	  {
				      while(true)
					  {
					      if(!Keyboard :: isKeyPressed(Keyboard :: Escape))
					          main();//��������� � ������
				      }
				  }
			  } 
		 }
			if (time < 0 && right < 20) { //���� ����� �����������, �� ��������� �������� ������ 20

			 Texture texture;
			 texture.loadFromFile("flag.png");
			 spr.setTexture(texture);
			 Sprite fon;
				 Texture fonTexture;
				 fonTexture.loadFromFile("fon1.jpg");
				 fon.setTexture(fonTexture);
			 std::ostringstream rightStr;
		rightStr << right;
		std::ostringstream str1;
		str1 << (right*(time/10000 + 1) * 10)*level;
			 Text text("", font, 30);
			 text.setColor(Color :: White);
			 text.setPosition(150, 200);
			 ostringstream str2;
		str2 << key[level-1];
			 text.setString("���� ����� ������� - ���� ��������!\n          �� ������ ������ " + rightStr.str() +" ����(�)\n                    ��� ����: " + str1.str() + " \n\n      ���� �� ������ ������ ���: " + str2.str() +"\n������� Esc ��� ������ � ������� ����");  
				 window.clear();
				 window.draw(fon);
				 window.draw(leveltext);
				 for(int i = 0; i < 25; i++)
				 {
				  Texture rect;
				   Sprite s;
				  if(isRight[i] == 1){
				  rect.loadFromFile("green.jpg");
				  }
				  if(isRight[i] == 2)
				  {
				   rect.loadFromFile("red.jpg");
				  }
				  s.setPosition(100 + 24*i, 90);
				  s.setTexture(rect);
				  Text chartext(string[i], font, 30);
				  chartext.setPosition(100 + 24*i, 80);
				  chartext.setColor(Color :: White);
				  window.draw(s);
				  window.draw(chartext);
				  
				 }
				 window.draw(load);
				 window.draw(spr);
				 window.draw(leveltext);
		window.draw(text);
window.display();
				while (true){
						 if(Keyboard :: isKeyPressed(Keyboard :: Escape))
						  while(true){
						  if(!Keyboard :: isKeyPressed(Keyboard :: Escape))
					     	main();
						  }
						} 
			} 
			 if(level != 25){//���� ������� �� 25
				if (right>=20) { //���� ���������� ������ ��� ����� 20
					level++;//������� �� ��������� �������
				}
				}else//�����(�. �. ���� ������� 25)
				{
				 Text text("", font, 30);
				 text.setColor(Color :: Black);
				 text.setPosition(200,250);
				 text.setString("�� �������!!! ������ �� �������\n ������ ��������!\n �����������!!!\n ������� Esc ��� ������ �� ����");
				 t.loadFromFile("molodetz.jpg");
				 load.setTexture(t);
				 load.setPosition(0,0);
				 load.setTextureRect(IntRect(0, 0, 800, 600));
				 window.clear();
				 ostringstream strtime;
				 strtime << int(time*10)/10.0;
				 window.draw(load);
				 window.draw(text);
				 window.display();
				 while(true)
				 {
				  if(Keyboard :: isKeyPressed(Keyboard :: Escape))
				   exit(0);
				 }
				}
   }

return 0;

}