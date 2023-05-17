#include "doctest.h"
#include "sources/Cowboy.hpp"
#include "sources/Ninja.hpp"
#include "sources/Team.hpp"
#include "sources/SmartTeam.hpp"

TEST_CASE("Point testing") {
  Point p1(0, 6);
  Point p2(9, 0);
  CHECK(p1.distance(Point(0, 0)) == 6);
  CHECK_FALSE(p1.distance(Point(0, 0)) == 12);
  CHECK(p2.distance(Point(0, 0)) == 9);
  CHECK_FALSE(p1.distance(Point(0, 0)) == 32);

  // lower distance than the distance between p1 and p2
  Point p3 = Point::moveTowards(p1, p2, 1.5);
  CHECK(p1.distance(p3) == 1.5);

  // higher distance than the distance between p1 and p2
  Point p4 = Point::moveTowards(p1, p2, 31);
  CHECK(p1.distance(p4) == p1.distance(p2));
}

TEST_CASE("Cowboy test") {
  Cowboy mes("messi", Point(2, 3));
  OldNinja ron("ronaldo", Point(4, 6));

  // cant shoot himself
  CHECK_THROWS(mes.shoot(&mes));

  // shoot with empty stack bullets
  mes.shoot(&ron);
  mes.shoot(&ron);
  mes.shoot(&ron);
  mes.shoot(&ron);
  mes.shoot(&ron);
  mes.shoot(&ron);
  int hp = ron.getLife();
  CHECK(mes.hasBullets());
  mes.shoot(&ron);
  CHECK(hp == ron.getLife());
  CHECK_FALSE(mes.hasBullets());
  
  // reload
  mes.reload();
  CHECK(mes.hasBullets());
  mes.shoot(&ron);
  CHECK(hp!=ron.getLife());
}

TEST_CASE("Ninja testing"){
  TrainedNinja a("ariel",Point(1,2));
  YoungNinja y("yuval",Point(3,4));
  
  // slash doesn't supposed to make damage
  int beforeHP = a.getLife();
  y.slash(&a);
  CHECK(beforeHP==a.getLife());
}

TEST_CASE("Team testing") {
  Cowboy *a = new Cowboy("Alon", Point(2, 2));
  Cowboy *j = new Cowboy("John", Point(6, 0));
  Team t1(a);
  CHECK_THROWS(t1.attack(NULL));
  CHECK_THROWS(t1.attack(&t1));

  // add leader again
  CHECK_THROWS(t1.add(a));

  // add the same member twice
  t1.add(j);
  CHECK_THROWS(t1.add(j));

  // add more than 10 members
  t1.add(new Cowboy("Alon", Point(1, 1)));
  t1.add(new Cowboy("Alon", Point(2, 1)));
  t1.add(new Cowboy("Alon", Point(3, 1)));
  t1.add(new Cowboy("Alon", Point(4, 1)));
  t1.add(new Cowboy("Alon", Point(5, 1)));
  t1.add(new Cowboy("Alon", Point(6, 1)));
  t1.add(new Cowboy("Alon", Point(7, 1)));
  t1.add(new Cowboy("Alon", Point(8, 1)));
  CHECK_THROWS(t1.add(new Cowboy("Alon", Point(9, 1))));
}

TEST_CASE("SmartTeam test"){
  Cowboy c1("c1",Point(1,1));
  Cowboy c2("c2",Point(1,1));
  Cowboy c3("c3",Point(1,1));
  OldNinja n1("n1",Point(1,2));
  TrainedNinja n2("n2",Point(1,2));
  YoungNinja n3("n3",Point(1,2));
  SmartTeam st(&c1);
  Team t(&c1);
  st.add(&c2);
  t.add(&c2);
  st.add(&c3);
  t.add(&c3);
  st.add(&n1);
  t.add(&n1);
  st.add(&n2);
  t.add(&n2);
  st.add(&n3);
  t.add(&n3);
  while(t.stillAlive()&&st.stillAlive()){
    st.attack(&t);
    if(t.stillAlive())
      t.attack(&st);
  }
  CHECK(st.stillAlive());
  CHECK_FALSE(t.stillAlive());
}