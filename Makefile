a.out: main.o AllExeptions.o commonTools.o Game.o Room.o Detective.o Doctor.o GodFather.o Joker.o Mafia.o Player.o RouinTan.o Silencer.o Villager.o Vote.o
	g++ -g -fsanitize=address -fno-omit-frame-pointer main.o AllExeptions.o commonTools.o Game.o Room.o Detective.o Doctor.o GodFather.o Joker.o Mafia.o Player.o RouinTan.o Silencer.o Villager.o Vote.o
main.o: main.cpp
	g++ -c -g -fsanitize=address -fno-omit-frame-pointer main.cpp
AllExeptions.o: AllExeptions.cpp
	g++ -c -g -fsanitize=address -fno-omit-frame-pointer AllExeptions.cpp
commonTools.o: commonTools.cpp
	g++ -c -g -fsanitize=address -fno-omit-frame-pointer commonTools.cpp
Game.o: Game.cpp
	g++ -c -g -fsanitize=address -fno-omit-frame-pointer Game.cpp
Room.o: Room.cpp
	g++ -c -g -fsanitize=address -fno-omit-frame-pointer Room.cpp
Detective.o: Detective.cpp
	g++ -c -g -fsanitize=address -fno-omit-frame-pointer Detective.cpp
Doctor.o: Doctor.cpp
	g++ -c -g -fsanitize=address -fno-omit-frame-pointer Doctor.cpp
GodFather.o: GodFather.cpp
	g++ -c -g -fsanitize=address -fno-omit-frame-pointer GodFather.cpp
Joker.o: Joker.cpp
	g++ -c -g -fsanitize=address -fno-omit-frame-pointer Joker.cpp
Mafia.o: Mafia.cpp
	g++ -c -g -fsanitize=address -fno-omit-frame-pointer Mafia.cpp
Player.o: Player.cpp
	g++ -c -g -fsanitize=address -fno-omit-frame-pointer Player.cpp
RouinTan.o: RouinTan.cpp
	g++ -c -g -fsanitize=address -fno-omit-frame-pointer RouinTan.cpp
Silencer.o: Silencer.cpp
	g++ -c -g -fsanitize=address -fno-omit-frame-pointer Silencer.cpp
Villager.o: Villager.cpp
	g++ -c -g -fsanitize=address -fno-omit-frame-pointer Villager.cpp
Vote.o: Vote.cpp
	g++ -c -g -fsanitize=address -fno-omit-frame-pointer Vote.cpp
