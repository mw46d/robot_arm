typedef struct action {
  int target;
  int pos;
} action_t;

#define A_WAIT		20
#define A_RELEASE	21
#define A_GRAB		22	// pos is used as marker for the item,
				// 1 - nail, 2 - pencil, 3 - pipe, 4 - TT ball
#define A_BONUS		23
#define A_NORTH		24
#define A_WEST		25
#define A_EAST		26
#define A_PARK		27
#define A_END		28
#define A_INPUT         29
#define A_DELAY         30      // pos is used to spec the millis to delay
#define A_SPEED         31      // pos is used as value,
                                // 1 - slow, 2 - faster
#define A_START         32
#define A_TOP           33

#define B_LEFT		1
#define B_RIGHT		2

static action_t action_array[] = {
  /* move out of park */
  { 1, 6060 },
  { A_WAIT, 0 },
  
  { A_SPEED, 2 },

  // Move to the start position
  { A_START, 0 },

  // Drop the helper ring
  { 0, 7400 }, { 2, 7300 }, { 3, 5908 }, { A_WAIT, 0 },
  { 1, 5200 },
  { A_RELEASE, 0 }, { A_SPEED, 2 }, 
  { 1, 6060 }, { A_WAIT, 0 },
  
  // 1. TT Ball
  { 1, 6060 }, { 0, 8400 }, { 3, 6148 }, {4, 8916 }, { A_WAIT, 0 },
  { 1, 5480 }, { 2, 7920 }, 
  { A_GRAB, 4 }, { A_WEST, 0 },
  
  // 2. TT Ball
  { 0, 7912 }, { 3, 5424 }, { A_DELAY, 250 },
  { 2, 8384 }, { A_WAIT, 0 },
  { 1, 5780 },
  { A_GRAB, 4 }, { A_NORTH, 0 },
  
  // 3. TT Ball
  { 0, 7200 }, { 2, 8384 }, { 3, 5424 }, { A_WAIT, 0 },
  { 1, 5804 },
  { A_GRAB, 4 }, { A_EAST, 0 },
  
  // 4. TT Ball
  { 0, 6800 }, { A_WAIT, 0 },
  { 3, 5424 }, { 4, 6360 }, { 2, 8140 }, { A_WAIT, 0 },
  { 1, 5668 },
  { A_GRAB, 4 },
  
  // Helper position
  { 1, 6060 }, {0, 7504 }, { 2, 7120 }, { 3, 5424 }, { A_WAIT, 0 },
  { 1, 5060 },
  { A_RELEASE, 0 },
  { 1, 6060 }, { A_WAIT, 0 },
  
  // 3 nail
  // position
  { 1, 6060 }, { 0, 7584 }, { 2, 8384 }, { 3, 5424 }, { 4, 7700 }, { 5, 6592 }, { A_WAIT, 0 },
  { 1, 5560 },
  { A_GRAB, 1 }, { A_BONUS, 0 }, 
  
  // 3 pencil
  // position
  { 0, 9868 }, { 3, 5424 }, { 4, 7700 }, { 5, 6592 }, { A_WAIT, 0 },
  { 2, 8384 }, { A_DELAY, 250 },
  { 1, 5608 },
  { A_GRAB, 2 }, { 1, 6060 }, { 2, 6500 }, { A_WAIT, 0 },
  { A_BONUS, 0 },
  
  // 3 pipe
  // position
  { 0, 5180 }, { 3, 5120 }, { 4, 7700 }, { 5, 6592 }, { A_WAIT, 0 },
  { 2, 8384 }, { A_WAIT, 0 },
  { 1, 5800 },
  { A_GRAB, 3 }, { 1, 6060 }, { 2, 6500 }, { A_WAIT, 0 },
  { A_BONUS, 0 }, 

  // 1 nail
  // position
  { 0, 8610 }, { 2, 8048 }, { 3, 5424 }, { 4, 7700 }, { 5, 6592 }, { A_WAIT, 0 },
  { 1, 5368 },
  { A_GRAB, 1 }, { A_EAST, 0 },
  
  // 2 nail
  // position
  { 0, 8140 }, { 2, 8384 }, { 3, 5424 }, { 4, 7700 }, { 5, 6592 }, { A_WAIT, 0 },
  { 1, 5560 },
  { A_GRAB, 1 }, { A_EAST, 0 },
  
  // 4 nail
  // position
  { 0, 6984 }, { 3, 5424 }, { 4, 7700 }, { 2, 8384 }, { 5, 6592 }, { A_WAIT, 0 },
  { 1, 5560 },
  { A_GRAB, 1 }, { A_EAST, 0 },
  
  // 5 nail
  // position
  { 0, 6664 }, { 3, 5424 }, { 4, 7700 }, { 2, 8048 }, { 5, 6592 }, { A_WAIT, 0 },
  { 1, 5288 },
  { A_GRAB, 1 }, { A_EAST, 0 },

  // 1 pencil
  // position
  { 0, 10700 }, { 3, 5872 }, { 4, 9408 }, { 5, 6592 }, { A_WAIT, 0 },
  { 2, 7800 }, { A_WAIT, 0 },
  { 1, 5480 },
  { A_GRAB, 2 }, { A_NORTH, 0 },

  // 2 pencil
  // position
  { 0, 10320 }, { 3, 5424 }, { 4, 7700 }, { 5, 6592 }, { A_WAIT, 0 },
  { 2, 8384 }, { A_WAIT, 0 },
  { 1, 5540 },
  { A_GRAB, 2 }, { A_NORTH, 0 },

  // 4 pencil
  // position
  { 0, 9700 }, { 3, 5424 }, { 4, 7000 }, { 5, 6592 }, { A_WAIT, 0 },
  { 2, 8384 }, { A_DELAY, 250 },
  { 0, 9368 }, { A_WAIT, 0 },
  { 1, 5608 },
  { A_GRAB, 2 },
  { 4, 2500 }, { 1, 6060 }, { 0, 9700 }, { A_WAIT, 0 },
  { A_NORTH, 0 },

  // 5 pencil
  // position
  { 3, 5424 }, { 2, 8048 }, { A_WAIT, 0 },
  { 0, 9120 }, { 4, 6200 }, { 5, 6592 }, { A_WAIT, 0 },
  { 1, 5408 },
  { A_GRAB, 2 },
  { 4, 2500 }, { 1, 6060 }, { 0, 9500 }, { A_WAIT, 0 },
  { A_NORTH, 0 },

  // 1 pipe
  // position
  { 0, 6088 }, { 2, 8048 }, { 3, 5424 }, { 4, 8000 }, { 5, 6592 }, { A_WAIT, 0 },
  { 1, 5248 },
  { A_GRAB, 3 },
  { 1, 6060 }, { A_WAIT, 0 },
  { 4, 4000 }, { 0, 7000}, { A_WAIT, 0 },
  { A_WEST, 0 },

  // 2 pipe
  // position
  { 0, 5700 }, { A_WAIT, 0 },
  { 2, 8384 }, { 3, 5424 }, { 4, 7700 }, { 5, 6592 }, { A_WAIT, 0 },
  { 1, 5588 },
  { A_GRAB, 3 }, { A_WEST, 0 },

  // 4 pipe
  // position
  { 0, 4632 }, { A_WAIT, 0 },
  { 2, 8384 }, { 3, 5424 }, { 4, 7000 }, { 5, 6592 }, { A_WAIT, 0 },
  { 1, 5688 },
  { A_GRAB, 3 }, { A_WEST, 0 },

  // 5 pipe
  // position
  { 0, 4280 }, { A_WAIT, 0 },
  { 2, 8080 }, { 3, 5424 }, { 4, 6200 }, { 5, 6592 }, { A_WAIT, 0 },
  { 1, 5640 },
  { A_GRAB, 3 }, { A_WEST, 0 },
  
  // Helper position - take TT ball
  { 0, 7504 }, { 2, 7120 }, { 3, 5424 }, { A_WAIT, 0 },
  { 1, 5060 }, { A_WAIT, 0 },
  { A_GRAB, 4 },

  { A_TOP, 0 },
  // Done;-)
  
  { A_RELEASE, 0 },
  { 2, 8000 }, { 1, 6060 }, { A_DELAY, 250 },
  
  { A_PARK, 0},
  
  { A_END, 0 },
};

static int ended = 0;
static unsigned long start_time;
static int index = 0;

void setup() {
  pinMode(7,OUTPUT);
  pinMode(7,HIGH);
  delay(500);
  pinMode(7,LOW);
  
  Serial.begin(115200);
  Serial1.begin(115200);
  delay(1000);

  readInput("Please enter a char to move to the start position");
  
  // Initial park position
  set_accel(5, 150); set_speed(5, 150);
  set_accel(4, 150); set_speed(4, 150);
  set_accel(3, 9); set_speed(3, 20);
  set_accel(2, 6); set_speed(2, 15);
  set_accel(1, 6); set_speed(1, 15);
  set_accel(0, 12); set_speed(0, 12);
 
  set_target(0, 6360);
  set_target(1, 4848);
  set_target(2, 8384);
  set_target(3, 8664);
  set_target(4, 7700);
  set_target(5, 2048);
  wait();

  start_time = millis();  
}

void loop() {
  while (action_array[index].target != A_END && ended == 0) {
    switch (action_array[index].target) {
      case A_BONUS:
          bonus(B_LEFT);
          break;
      case A_DELAY:
          delay(action_array[index].pos);
          break;
      case A_EAST:
          east();
          break;
      case A_GRAB:
          grab(action_array[index].pos);
          break;
      case A_NORTH:
          north();
          break;
      case A_PARK:
          park();
          break;
      case A_RELEASE:
          release();
          break;
      case A_SPEED:
          adjust_speed(action_array[index].pos);
          break;
      case A_START:
          startup();
          break;
      case A_TOP:
          top();
          break;
      case A_WAIT:
          wait();
          break;
      case A_WEST:
          west();
          break;
      default:
          set_target(action_array[index].target,
                     action_array[index].pos);
    }
    index++;

    if (Serial.available() > 0) {
                // read the incoming byte:
      int incomingByte = Serial.read();

                // say what you got:
      Serial.print("I received: ");
      Serial.println(incomingByte, DEC);
  
      if (incomingByte == 80 || incomingByte == 112) {
        ended = 1;
        park();
      }
    }
  }
  
  if (start_time != 0) {
    Serial.print("time taken= ");
    Serial.println(millis() - start_time);
    
    start_time = 0;
  }
}

void wait() {
  int ret;
  unsigned long start_time = millis();
  
  Serial.print("In wait (");
  Serial.print(index);
  Serial.print(") ... ");
  
  do {
    Serial1.write(0xAA);
    Serial1.write(0x93);

    while (Serial1.available() == 0) {
      delay(10);
    }
  
    while (Serial1.available() > 0) {
                // read the incoming byte:
      ret = Serial1.read();
    }
  } while (ret);
  
  delay(250);
  Serial.print("Waited ");
  Serial.println(millis() - start_time);
//  readInput("Enter a char to continue");
}

void park() {
  set_target(1, 6060);
  wait();
  // Initial park position
  set_target(0, 6360);
  set_target(2, 8384);
  set_target(3, 8664);
  set_target(4, 7700);
  set_target(5, 2048);
  wait();
  set_target(1, 4848);
}

void release() {
  wait();
  set_target(5, 6592);
  wait();
}

void grab(int item) {
  wait();
  
  switch (item) {
    case 1:	// nail
	set_target(5, 3040); // 2140
        break;
    case 2:	// pencil
	set_target(5, 3500); // 2300
        break;
    case 3:	// pipe
        set_target(5, 4820); // 4400
        break;
    case 4:	// TT ball
        set_target(5, 3300);
        break;
  }
  
  wait();
}

void bonus(int loc) {
  if (loc == B_LEFT) {
		// bring to bonus box left
    set_target(1, 6060);
    adjust_speed(1);
    set_target(2, 5114); // 5184
    set_target(0, 7584);
    wait();
    set_target(3, 3700);
    set_target(4, 7700);
    set_target(0, 8566); // 8524, 8496
    wait();
    set_target(1, 5068); // 4968
    release();
    adjust_speed(2);
    set_target(1, 6060);
    wait();
  }
  else if (loc == B_RIGHT) {
  }
}

void east() {
		// bring to East Box
  set_target(1, 6060);
  set_target(2, 6680);
  set_target(3, 2428);
  wait();
  set_target(4, 7700);
  set_target(0, 6088);
  set_target(2, 7684);
  wait();
  set_target(1, 5918); // 5848
  release();
  set_target(1, 6060);
  set_target(2, 6680);
  delay(250);
}

void north() {
                // bring to North Box
  set_target(1, 6060);
  set_target(2, 8000);
  wait();
  set_target(0, 7680); // 7624
  set_target(3, 2704);
  set_target(4, 7700);
  wait();
  set_target(2, 6610); // 6630
  set_target(1, 5188); // 5028
  release();
  set_target(1, 6060);
  set_target(2, 6400);
  delay(250);
}

void west() {
                // bring to West Box
  set_target(1, 6060);
  set_target(2, 6680);
  set_target(3, 2428);
  wait();
  set_target(4, 7700);
  set_target(0, 9124);
  wait();
  set_target(2, 7684);
  set_target(1, 5918); // 5848
  release();
  set_target(1, 6060);
  set_target(2, 6400);
  delay(250);
}

void startup() {
               // bring the robot into the start position
  set_target(0, 7504);
  set_target(1, 6200);
  set_target(2, 2440);
  set_target(3, 4400);
  set_target(5, 6592);
  wait();
  
  readInput("Enter a char to grab helper");
  grab(1);
  readInput("=== Enter a char to start! ===");
  start_time = millis();
}

void top() {
               // bring the robot into the start position
  set_target(0, 7504);
  set_target(1, 6200);
  set_target(2, 2440);
  set_target(3, 4400);
  wait();
  
  Serial.println("=== Done! ===");
  Serial.print("time taken= ");
  Serial.println(millis() - start_time);
  
  readInput("Enter a char to go back to park");
}

void set_target(unsigned char servo, unsigned int target) {
  Serial1.write(0xAA);
  // Serial1.write(12);
  Serial1.write(0x84); //command number
  Serial1.write(servo); //servo number
  Serial1.write(target & 0x7F);
  Serial1.write((target >> 7) & 0x7F);
}

void set_speed(unsigned char servo, unsigned int target) {
  Serial1.write(0xAA);
  // Serial1.write(12);
  Serial1.write(0x87); //command number
  Serial1.write(servo); //servo number
  Serial1.write(target & 0x7F);
  Serial1.write((target >> 7) & 0x7F);
}

void set_accel(unsigned char servo, unsigned int target) {
  Serial1.write(0xAA);
  // Serial1.write(12);
  Serial1.write(0x89); //command number
  Serial1.write(servo); //servo number
  Serial1.write(target & 0x7F);
  Serial1.write((target >> 7) & 0x7F);
}

void adjust_speed(unsigned int target) {
  switch (target) {
    case 1:
        set_accel(3, 9); set_speed(3, 20);
        set_accel(2, 6); set_speed(2, 15);
        set_accel(1, 6); set_speed(1, 15);
        set_accel(0, 12); set_speed(0, 12);
        break;
    case 2:
        set_accel(3, 9); set_speed(3, 20);
        set_accel(2, 9); set_speed(2, 25);
        set_accel(1, 9); set_speed(1, 25);
        set_accel(0, 15); set_speed(0, 20);
        break;
  }        
}

void readInput(const char *str) {
  int incomingByte;

  if (ended > 0) {
    return;
  }
  
  if (str != NULL) {
    Serial.println(str);
  }
  else {
    Serial.println("Enter a Char: ");
  }

  while (Serial.available() == 0) {
    delay(100);
  }
  
  while (Serial.available() > 0) {
                // read the incoming byte:
    incomingByte = Serial.read();

                // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }
  
  if (incomingByte == 80 || incomingByte == 112) {
    ended = 1;
    park();
  }
}
