#include <SFML/Graphics.hpp> //подключение графической библиотеки
#include <iostream> 
#include <sstream>

using namespace sf;
using namespace std; 

RenderWindow window(sf::VideoMode(800, 600), L"Клавиатурный тренажёр");//инициализация окна
Font font;//создание объекта шрифта
Sprite load;//основной спрайт в окне
int level;
int alphabet(char ch, char alphabet[])//меняет char на номер клавиши в Keyboard
        {
 

            //массив всех английских букв
            for (int ii = 0;ii<25;ii++)//цикл ищет порядковый номер буквы в алфавите
            {
                if (char(ch) == alphabet[ii]){return ii;}
            }
 
 
     }


void array(char *m) //инициализация массива символов
{
	for (int i = 'a', j = 0; i <= 'z'; i++, j++) { //цикл заполняет массив буквами
		m[j] = char(i); 
	} 
} 

String random_string(int lvl, char *m) //метод для генерации случайной строки
{ 
 string str;
 window.clear();
	srand(time(NULL));
	for (int j = 0,s; j < 25; j++) 
	{ 
		s = rand() % (lvl+1); //выбор случайной буквы в зависимости от уровня
		char c = m[s];
		if(c == ' ')//если сгенерировался пробел продолжить менять эту же букву
		{
		 j--;
		}
		else{//иначе добавить буквы к строке
		str += c;
		}
	}
	return str;
} 

int menu(int key[] ) //меню и выбор начала новой игры или загрузки уровня
{ 
	int number = 1;//переменная для хранения результата ввода пользователя(number)
	Text text("", font, 20);//инициализация рисуемого текста с нужным шрифтом и размером
	text.setColor(Color :: White);
	text.setPosition(110 , 200);
	text.setString("\n\n\nКурсовая работа по информатике 'Клавиатурный тренажер'\n                      Нажмите 'Пробел' для начала игры");
	 window.clear();   // _
	 window.draw(load);//  |_рисование спрайта и текста
window.draw(text);     //  |
window.display();    //   -

while(true){//цикл ожидает нажатия пробела
 Event event;
			 while (window.pollEvent(event))//цикл обрабатывающий события
	  {
	   if (event.type == sf::Event::Closed){//если окно закрывается
window.close();
exit(0);
	   }
	  }
 if(Keyboard :: isKeyPressed(Keyboard :: Space))//если нажимается пробел то выходим из цикла
	 break;
	}
	while (true) //выбор начала новой игры или загрузки уровня
{ 
	{
	 text.setPosition(270 , 230);
	 text.setString("\n            Нажмите:\n\"1\" для начала новой игры\n\"2\" для загрузки уровня\n\"Esc\" для выхода из игры"); 
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
 if(Keyboard :: isKeyPressed(Keyboard :: Num1)){//если нажата "1"
 number = 1;
 break;}
if(Keyboard :: isKeyPressed(Keyboard :: Num2)){//если нажата "2"
 while(true){
  if(!Keyboard :: isKeyPressed(Keyboard :: Num2))
  {
   break;
  }
 
 }
 number = 2;
 break;}
if(Keyboard :: isKeyPressed(Keyboard :: Escape)){//если нажата "Esc"
exit(0);
break;
}
}
		if (number == 1) //если пользователь нажал 1
		{ 
		 text.setPosition(140 , 200);
		 text.setString("\n                     Вы решили начать новую игру\n          Введите строку, которую увидите на экране\n         На выполнение задачи вам дается 10 секунд\nЗа каждую верно введенную букву прибавляется 0,1 сек\n                    В противном случае убавляется\n                  Для начала игры нажмите \"Пробел\""); 
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
		  if(Keyboard :: isKeyPressed(Keyboard :: Space))//если нажат пробел
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
		if (number == 2)  //если пользователь нажал 2
		{ 
	    	  text.setPosition(230 , 250);
		      
			  int cheat = 0;//введённый ключ
			  int beginning = 0;//один раз игнорирует нажатие клавиши, для устранения ошибок
			       bool flag = false;//булевый флаг
			       while(true)//ввод кода
			       {
					   if(flag)
						   break;
					   Event ev;
					   while(window.pollEvent(ev))
					   {
						if(beginning > 0){
					    	if(ev.type == Event :: KeyPressed && cheat/1000<1)//если нажата клавиша
					    	{

								   if(ev.key.code == Keyboard :: Num0)//проверяет, какая нажата(switch не использован из-за багов в нем)
								   {
									   cheat = cheat*10+0;//"приписывает" справа к числу цифру								
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
									   cheat = cheat/10;//"стирает" одну цифру справа									
								   }
								   if(ev.key.code == Keyboard :: Return)//если нажат Enter, т. е. пользователь подтвердил ввод
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
					   if(cheat != 0){//если пользователь ничего не вводил то код не показывается
					   text.setString("\nВы выбрали пункт \"Загрузить уровень\"\nВведите ключ соответствующего уровня:" + str.str());
					   }
					   else{
					   text.setString("\nВы выбрали пункт \"Загрузить уровень\"\nВведите ключ соответствующего уровня:"); 
					   }
	          window.clear();
			  window.draw(load);
              window.draw(text);
              window.display();
			       }
			  for (int i = 0; i < 25; i++) 
			  { 
			    	if (cheat == key[i]) //если код совпал
			     	{
				       std::ostringstream str;
	                   str << (i+1);	
		               text.setPosition(250, 230);
		               text.setString("\n\n        Вы открыли " + str.str() +" уровень\n Для начала игры нажмите \"Пробел\"");
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
		                   if(Keyboard :: isKeyPressed(Keyboard :: Space))//если нажат пробел выйти из цикла ввода кода
		                       break;
		               }
					   return i + 1; 
				   } 
			    }
			    text.setString("\nВведенного вами ключа не существует\nНажмите \"Esc\" для выхода в главное меню"); 
		        window.clear();
				window.draw(load);
                window.draw(text);
                window.display();
                while(true)
                {
                    if(Keyboard :: isKeyPressed(Keyboard :: Escape))//если нажата "Esc" выйти из цикла
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
    t.loadFromFile("fon.jpg");//инициализаияя текстуры
	load.setTexture(t);//загрузка текстуры в спрайт
    load.setTextureRect(IntRect(0, 0, 800, 600));
	load.setPosition(0,0);
    Font localFont;//создание локального шрифта
	localFont.loadFromFile("Font.ttf");//загрузка шрифта из файла
	font = localFont;
	
	//массив с кодами
	int key[] = { 1320, 5051, 3299, 9488, 2620, 4744, 6164, 2405, 8821, 2275, 1030, 9325, 9094, 2243, 9572, 5847, 5741, 1509, 6272, 5109, 4976, 6393, 5477, 2904, 5817 };
	
	float time = 10;//переменная отвечающая за оставшееся время
	int right = 0, nright = 0;//переменные отвечающие за кол - во правильно и неправильно введённных букв
	char mass[28];//переменные - кол-во правильно введённых букв, неправильно и массив с алфавитом
	level = menu(key);//выбор уровня
    while (window.isOpen()){//пока окно открыто
        Event locevent;
        while (window.pollEvent(locevent))
	    {
		    if (locevent.type == sf::Event::Closed)
			 window.close();
	    }
	    window.clear();
        window.draw(load);
        window.display();
        t.loadFromFile("Load.jpg");//загрузка текстуры из файла
        load.setTexture(t);
        load.setPosition(50, 500);
        array(mass);//инициализация алфавита
		//инициализация переменных
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
		int isRight[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//массив для хранения правильности ввода для каждой буквы
		Clock clock;//создаём "часы" для измерения прошедшего времени
	    clock.restart();
			for (int j = 0; j < 25; j+= 0)//цикл по всем буквам
			{
			    Texture texture;
				texture.loadFromFile("arrow.png");
				Sprite fon;
				Texture fonTexture;
				fonTexture.loadFromFile("fon1.jpg");
				fon.setTexture(fonTexture);
				spr.setTexture(texture);
				spr.setPosition(100+24*j, 60);
				load.setTextureRect(IntRect(0, 0, 600/10*(time), 33));//"перезагружает" картинку с оставшимся временем
			    c = string[j];
			    window.clear();
    			window.draw(fon);
				leveltext.setString("\nУровень " + str.str() + "\n");
			    window.draw(leveltext);
				for(int i = 0; i < 25; i++)//цикл загружающий все изображения букв
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
			    Text ttime("Оставшееся время "+strtime.str(),font,20);
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
				    Text ttime("Оставшееся время "+strtime.str(),font,20);
				    ttime.setPosition(50, 450);
				    window.draw(load);
				    window.draw(ttime);
				    window.draw(spr);
				    window.draw(leveltext);
				    window.display();


	                if (event.type == sf::Event::KeyPressed)//если нажата клавиша(любая)
	                {
				       if(event.key.code == Keyboard :: Key(alphabet(c, mass)))//если правильная
			           {
			               isRight[j] = 1;//в массиве числу с индексом, соответствующим порядковому номеру набираемой буквы, присваивается 1
			               j++;//переходит к следующей букве
					       right++;//добавляет 1 к правильным вводам
					       while(true)//ждет отжатия клавиши
					       {
					           if(!Keyboard :: isKeyPressed(Keyboard :: Key(alphabet(c, mass))))
						       {
					               time += 0.1;//прибавляется время
					               break;
					           }
					       }				
					       break;
					   }
					   else //если неправильная
				       { 
				           isRight[j] = 2;//в массиве числу с индексом, соответствующим порядковому номеру набираемой буквы, присваивается 2
				           time -= 0.1;//вычитается время
					       j++;//переходит к следующей букве
					       printf("\a");//издает звук ошибки
					       nright++; //добавляет 1 к неправильным вводам
				       }
	               }
	               if (event.type == sf::Event::Closed)
				   {
                       window.close();
                       exit(0);
	               }
	          }
              if(time < 0){j = 24; break;}//если время закончилось, выйти из цикла
			  if (nright >= 5){ j=24;break; }//если слишком много ошибок, выйти из цикла
	      }
		  if (nright >= 5)//если слишком много ошибок
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
			  text.setString("Вы сделали слишком много ошибок  - 5 шт!\n         Ключ от вашего уровня был: " + str.str() + "\nНажмите Esc для выхода в главное меню"); 
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
		 	  strtime << int(time*10)/10.0;//округление времени до десятых
		 	  Text ttime("Оставшееся время "+strtime.str(),font,20);
			  ttime.setPosition(50, 450);
			  window.draw(load);
			  window.draw(ttime);
			  window.draw(spr);
			  window.draw(leveltext);
	          window.draw(text);
              window.display();			
			  while (true)
			  {
	              if(Keyboard :: isKeyPressed(Keyboard :: Escape))//если нажат Ecs
			 	  {
				      while(true)
					  {
					      if(!Keyboard :: isKeyPressed(Keyboard :: Escape))
					          main();//вернуться к началу
				      }
				  }
			  } 
		 }
			if (time < 0 && right < 20) { //если время закончилось, но правильно введённых меньше 20

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
			 text.setString("Ваше время истекло - игра окончена!\n          Вы успели ввести " + rightStr.str() +" букв(ы)\n                    Ваш счёт: " + str1.str() + " \n\n      Ключ от вашего уровня был: " + str2.str() +"\nНажмите Esc для выхода в главное меню");  
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
			 if(level != 25){//если уровень не 25
				if (right>=20) { //если правильных больше или равно 20
					level++;//перейти на следующий уровень
				}
				}else//иначе(т. е. если уровень 25)
				{
				 Text text("", font, 30);
				 text.setColor(Color :: Black);
				 text.setPosition(200,250);
				 text.setString("Вы молодец!!! Теперь вы сможете\n быстро печатать!\n Поздравляем!!!\n Нажмите Esc для выхода из игры");
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