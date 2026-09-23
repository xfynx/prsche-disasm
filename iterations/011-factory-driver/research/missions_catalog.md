# Factory Driver 34 Missions Full Specification

Extracted from `FEData/Data/nfs5.fac` and `FEData/Locale/festrings.csv`.

## Mission 01 (Þ): So, you want to be part of the Porsche Test Team. Well, your credentials are all in order -- which is quite important, but lets see how you perform behind the wheel. Take the Porsche Boxster behind me out to the Weissach Skid Pad and drive around the cones by following the arrows. You must avoid hitting the cones, however. Each one knocked over adds time to your performance... and take too long, then you, my friend, may be looking elsewhere for work. The map will show you how the skid pad is laid out.

- **Base String ID**: 3001
- **Tier / Level**: 1
- **Briefing**: Applying Test
- **Tip**: You have been given an opportunity to work on the Porsche Test Team. This team enjoys a long history of performance and durability testing which has ensured that Porsche quality excels in every way. While working on the team, you will have many responsibilities including: training, car testing, demonstrations and the occasional challenge from other test drivers. Only the world's best drivers prosper on the Porsche Test Team. Do you have what it takes?
- **Fail Feedback**: Hey there, welcome to the team. Im Rolf and I'm the Test Driving Supervisor for the Porsche Test Team. Youre going to meet some of the other test drivers here the next few days.  Some of them might be a little tough on you because you are new, but dont worry, theyll warm up to you eventually. Just show them what you're made of and have fun out there.
- **Raw Parameters**: ints[0..15] = [3001, 0, 1, 3191, 222, 0, 0, 327681, 32, 1, 0, 0, 0, 0, 0, 805306368]

## Mission 02 (Þ): Since its your first day, we wont try anything too strenuous. How about we go for a spin out on the skid pad. There is a short slalom course set up for you out there. Lets see how you do with a twenty-six second time limit.

- **Base String ID**: 3015
- **Tier / Level**: 1
- **Briefing**: Simple Slalom
- **Raw Parameters**: ints[0..15] = [3015, 0, 1, 3191, 222, 0, 0, 327682, 32, 11, 0, 0, 0, 0, 0, 822083584]

## Mission 03 (Þ): Porsches are known around the world for their distinctive handling. Cornering is an art you must learn to be able to take these cars through an S-curve as fast as possible. You should be able to get through these turns in thirty-two seconds if your line is right. Keep an eye on the corners and you shouldnt have much problem at all. You'll be driving the classic Carrera RS out there... even a little damage could disqualify you.

- **Base String ID**: 3030
- **Tier / Level**: 1
- **Briefing**: S-turn
- **Raw Parameters**: ints[0..15] = [3030, 0, 1, 3191, 222, 0, 0, 327683, 34, 12, 1, 0, 0, 0, 0, 822083584]

## Mission 04 (Þ): Car control is a very important skill you will need to master to work successfully on the Porsche Test Team. Sometimes the car will spin on you and youll need to be able to recover. Complete a 360 degree spin to the right within the length of the cones and try to keep your speed up. Youll need to use your emergency brake to complete this exercise.   

- **Base String ID**: 3045
- **Tier / Level**: 1
- **Briefing**: 360 Spin
- **Raw Parameters**: ints[0..15] = [3045, 0, 1, 3191, 222, 0, 0, 327684, 32, 13, 0, 0, 0, 0, 0, 822083584]

## Mission 05 (Þ): Hi, %s. Im Frank and I'm one of the Senior Test Drivers here at Porsche. I've already heard that you're a pretty talented driver, but the top driver on the team is Stephanie. In all my years here, I have yet to see anyone handle a car like her, and thats why she's known as Ace. She and I have a bet going. Stephanie says it's possible to do the highway slalom in less than twenty-eight seconds... and I dont think so. Can you take that car out there and prove me wrong? 

- **Base String ID**: 3060
- **Tier / Level**: 1
- **Briefing**: Open Road Slalom
- **Raw Parameters**: ints[0..15] = [3060, 0, 1, 3191, 222, 0, 0, 196613, 12, 14, 1, 0, 0, 0, 0, 822083584]

## Mission 06 (Þ): I need you to do a car delivery for me. Get this 911 Turbo to the other side of Cote d'Azur, by the docks, as soon as possible. But watch out! The police are on patrol tonight. They won't pull you over... but they can get in your way. Be quick and good luck, but don't scratch her or there will be trouble.

- **Base String ID**: 3090
- **Tier / Level**: 1
- **Briefing**: Car Delivery 1
- **Raw Parameters**: ints[0..15] = [3090, 0, 1, 3191, 222, 0, 0, 131078, 8, 65552, 2, 0, 0, 0, 0, 822083584]

## Mission 07 (Þ): Thanks for helping me out on that bet with Frank. I knew that Turbo could do that highway slalom course quick. Now lets see how you drive on an extended slalom course, and remember, dont knock over any cones! You need to go from the old town to the forest in under fifty seconds. Good luck. I have a feeling youre going to need it, rookie.

- **Base String ID**: 3075
- **Tier / Level**: 1
- **Briefing**: Extended Slalom
- **Raw Parameters**: ints[0..15] = [3075, 0, 1, 3191, 222, 0, 0, 65543, 14, 15, 2, 0, 0, 0, 0, 822083584]

## Mission 08 (Þ): Hey, %s, Klaus and I just wrapped up some testing on the skid pad. We have a pretty challenging course set up. I did it in fifty-eight seconds.  Think you can beat that?

- **Base String ID**: 3105
- **Tier / Level**: 1
- **Briefing**: Franks Challenge
- **Raw Parameters**: ints[0..15] = [3105, 0, 1, 3191, 222, 0, 0, 196616, 32, 17, 0, 0, 0, 0, 0, 822083584]

## Mission 09 (Þ): %s, I have an urgent job for you. Get this Boxster out to the docks for shipping right away. Time is really tight, so I hope you can make it! Oh, and be sure you dont scratch her, or dont bother coming back.

- **Base String ID**: 3120
- **Tier / Level**: 1
- **Briefing**: Car Delivery 2
- **Raw Parameters**: ints[0..15] = [3120, 0, 1, 3191, 222, 0, 0, 131081, 16, 65554, 2, 0, 0, 0, 0, 822083584]

## Mission 10 (Þ): When I first started at Porsche, we had rally-style challenges. Some of the drivers here like to keep the tradition alive. You have to go out and knock over twelve cones on the course in the correct order. Well let you know where the next cone is as soon as you knock one over. You'll be driving back and forth all over the place - and to make it tougher, you might not get restarted in the direction you were going if you flip the car.

- **Base String ID**: 3135
- **Tier / Level**: 1
- **Briefing**: Capture the Flag 1
- **Raw Parameters**: ints[0..15] = [3135, 0, 1, 3191, 222, 0, 0, 327690, 34, 19, 1, 0, 0, 0, 0, 822083584]

## Mission 11 (Þ): Hey, %s, nice to finally meet you. Im Klaus, one of the mechanics here at Porsche. Can you do me a favor? Take this 993 Turbo out and test the emergency brake. Do a couple of 360 spins within the length of the cones and let me know how she feels.

- **Base String ID**: 3150
- **Tier / Level**: 1
- **Briefing**: More 360's
- **Raw Parameters**: ints[0..15] = [3150, 0, 1, 3191, 222, 0, 0, 262155, 32, 110, 0, 0, 0, 0, 0, 822083584]

## Mission 12 (Þ): We need you to demo a new 996 for an important customer. Push the car hard through the canyons - be fast, but make sure you dont scratch her. Follow the arrows and you wont get lost. Also, pay attention to where you are going, because if you have to be restarted, you might not be set in the right direction - and it may not be a successful demo.

- **Base String ID**: 3165
- **Tier / Level**: 1
- **Briefing**: Demo a 996
- **Raw Parameters**: ints[0..15] = [3165, 0, 1, 3191, 222, 0, 0, 131084, 34, 65647, 65537, 0, 0, 0, 0, 822083584]

## Mission 13 (Þ): %s, youve been with us a while now and its time to see if youre ready to be a full fledged Test Driver. We have set up the standard Test Driver testing course for you. Its what we use to grade all of our test drivers. Complete the course in the time limit to earn your promotion. And one more thing... the weather might not be perfect out there. Good luck.

- **Base String ID**: 3180
- **Tier / Level**: 1
- **Briefing**: 1st Promotion
- **Raw Parameters**: ints[0..15] = [3180, 0, 1, 3191, 222, 0, 0, 327693, 12, 112, 1, 0, 0, 0, 0, 822083584]

## Mission 14 (Ý): %s, theres a customer in town who came out to pick up their car from the Porsche Exclusive program. He came out a day early and is on a tight schedule. You have to get this car to him as soon as possible... and get it there without a scratch. 

- **Base String ID**: 3195
- **Tier / Level**: 2
- **Briefing**: Car Delivery 3
- **Raw Parameters**: ints[0..15] = [3195, 0, 2, 3342, 221, 0, 0, 131073, 13, 65557, 2, 0, 0, 0, 0, 838860800]

## Mission 15 (Ý): We need you to test out some of the adjustments Ive made to the 4 wheel drive system on the new Carrera 4. We have set up a run in the Alps. Be careful, though. The fresh snow makes for excellent testing conditions but can be very slippery.

- **Base String ID**: 3210
- **Tier / Level**: 2
- **Briefing**: Snow Testing
- **Raw Parameters**: ints[0..15] = [3210, 0, 2, 3342, 221, 0, 0, 262146, 11, 22, 1, 0, 0, 0, 0, 838860800]

## Mission 16 (Ý): Klaus is working on a project in a warehouse in Zone Industrielle and needs some parts. Can you run these out to him? He needs them as soon as possible. After you drop them off, get back here immediately to receive your next assignment. Be forewarned, getting restarted facing the right direction in this assignment can be a problem.

- **Base String ID**: 3225
- **Tier / Level**: 2
- **Briefing**: Klaus' Delivery
- **Raw Parameters**: ints[0..15] = [3225, 0, 2, 3342, 221, 0, 0, 131075, 16, 65559, 2, 0, 0, 0, 0, 838860800]

## Mission 17 (Ý): We just hired a new test driver to the team. His name is Billy. Ive set up the course for you and need you to show him the ropes out on the skid pad.

- **Base String ID**: 3240
- **Tier / Level**: 2
- **Briefing**: Billy's First Day
- **Raw Parameters**: ints[0..15] = [3240, 0, 2, 3342, 221, 0, 0, 327684, 32, 24, 65536, 0, 0, 0, 0, 838860800]

## Mission 18 (Ý): Hey there, %s. Think youre pretty fast? I heard youre some sort of hot shot. Well, I may be new here, but I dont want you stealing any of my glory, so its time I put you in your place. Ill race you on the hill later today. Then well see how fast you are

- **Base String ID**: 3255
- **Tier / Level**: 2
- **Briefing**: Billy's Challenge
- **Raw Parameters**: ints[0..15] = [3255, 0, 2, 3342, 221, 0, 0, 5, 10, 65561, 1, 0, 0, 0, 0, 838860800]

## Mission 19 (Ý): I made some modifications to the Boxster prototype. I need you to take it out on the skid pad and try it out. Its a pretty complex course, but you should be able to handle it.

- **Base String ID**: 3270
- **Tier / Level**: 2
- **Briefing**: Boxster Test
- **Raw Parameters**: ints[0..15] = [3270, 0, 2, 3342, 221, 0, 0, 262150, 32, 26, 0, 0, 0, 0, 0, 838860800]

## Mission 20 (Ý): Hey, %s, were going for a little race out on the country roads after work. I hear your reputation is at stake? Billy's been talking behind your back a lot. I think its time you taught this new kid a lesson, again. He seems to forget that you beat him earlier. But you better win the race... or Billy may never shut up.

- **Base String ID**: 3285
- **Tier / Level**: 2
- **Briefing**: Team Race 1
- **Raw Parameters**: ints[0..15] = [3285, 0, 2, 3342, 221, 0, 0, 196615, 10, 65563, 2, 0, 0, 0, 0, 838860800]

## Mission 21 (Ý): Dieters away on business tonight and were going into town to play a little game of Capture the Flag. Do you think you have the juice to beat ole Rolfs time? Last time I drove this route I set a new record and Im looking to set a newer one tonight. Just keep your eyes open and well let you know where to go. Don't drive too crazy, though, because you might get restarted facing the wrong direction.

- **Base String ID**: 3300
- **Tier / Level**: 2
- **Briefing**: Capture the Flag 2
- **Raw Parameters**: ints[0..15] = [3300, 0, 2, 3342, 221, 0, 0, 327688, 13, 28, 2, 0, 0, 0, 0, 838860800]

## Mission 22 (Ý): I hear theres an opening for the position of Chief Test Driver. Its between you and me for who gets the job. I just set an awesome time on the stunt course that Rolf set up out on the skid pad. Give it a go, I bet you cant beat my time.

- **Base String ID**: 3315
- **Tier / Level**: 2
- **Briefing**: Billy's Stunt Course
- **Raw Parameters**: ints[0..15] = [3315, 0, 2, 3342, 221, 0, 0, 9, 32, 29, 0, 0, 0, 0, 0, 838860800]

## Mission 23 (Ý): I've been thinking about retiring soon. There have been a lot of good days here at Porsche. Ive recommended to Dieter that you take my place as Chief Test Driver of the Porsche Test Team. He doesnt think youre ready and wants us to race on my old favorite stomping grounds to prove that youre up to it. To make this race extra special, well be driving one of the first cars I ever tested at Porsche, the 1973 Carrera RS. Good luck, kid. But Im warning you, I wont be holding any punches.

- **Base String ID**: 3330
- **Tier / Level**: 2
- **Briefing**: Thats a race Ill remember for years, thanks for the good times.
- **Raw Parameters**: ints[0..15] = [3330, 0, 2, 3342, 221, 0, 0, 327690, 34, 210, 2, 0, 0, 0, 0, 838860800]

## Mission 24 (ß): %s, were shipping this car off to the race team for a race next weekend. Put it through its paces out on this course before we ship it off. You should be able to whip through the course without much problem, but watch your time, I dont want to come out there and tow you back. 

- **Base String ID**: 3345
- **Tier / Level**: 3
- **Briefing**: Race Car Test
- **Raw Parameters**: ints[0..15] = [3345, 0, 3, 3495, 223, 0, 0, 262145, 32, 31, 0, 0, 0, 0, 0, 855638016]

## Mission 25 (ß): %s, I need you to drive me into town. Im late for my train and theyre waiting at the station for me. Theyll only hold it for a few more minutes.  Get me there fast... and in one piece.

- **Base String ID**: 3360
- **Tier / Level**: 3
- **Briefing**: Dieter's Late
- **Raw Parameters**: ints[0..15] = [3360, 0, 3, 3495, 223, 0, 0, 131074, 16, 65568, 65537, 0, 0, 0, 0, 855638016]

## Mission 26 (ß): Good to see you again, %s. Looks like youve been quite busy since I last saw you. Were doing some time trials through a slalom course out on the back roads. The track is pretty tight, Im not too sure you can handle it. This will be a good test of your skills.

- **Base String ID**: 3375
- **Tier / Level**: 3
- **Briefing**: Stephanie's Slalom
- **Raw Parameters**: ints[0..15] = [3375, 0, 3, 3495, 223, 0, 0, 65539, 9, 33, 1, 0, 0, 0, 0, 855638016]

## Mission 27 (ß): You were pretty fast last time, but youll never beat my time on the course I have set up. The only driver who has beaten my time is Stephanie, and shes the best there is. Youre just an amateur working with pros and this course will prove it. Your luck has to run out some time!  

- **Base String ID**: 3390
- **Tier / Level**: 3
- **Briefing**: Billy's Challenge 2
- **Raw Parameters**: ints[0..15] = [3390, 0, 3, 3495, 223, 0, 0, 4, 32, 34, 0, 0, 0, 0, 0, 855638016]

## Mission 28 (ß): People are saying that you might actually be a challenge for me, and that youre gunning for my title as Ace Driver. Ill give you a chance to race me if you can beat my time on the Alps switchbacks. 

- **Base String ID**: 3405
- **Tier / Level**: 3
- **Briefing**: Stephanie's Challenge
- **Raw Parameters**: ints[0..15] = [3405, 0, 3, 3495, 223, 0, 0, 65541, 11, 35, 1, 0, 0, 0, 0, 855638016]

## Mission 29 (ß): Hey, %s, youve been pretty busy lately, I hear. How about hanging out with a couple of us tonight? Were going out for a spin on the race track after we get off work. You game?

- **Base String ID**: 3420
- **Tier / Level**: 3
- **Briefing**: Team Race 2
- **Raw Parameters**: ints[0..15] = [3420, 0, 3, 3495, 223, 0, 0, 196614, 10, 36, 2, 0, 0, 0, 0, 855638016]

## Mission 30 (ß): %s, we are filming the new Porsche commercial this afternoon. We need you to drive the course. Stephanie usually does it, but shes out of town helping out the racing team. What you have to do is a 180 slide through the cones, drive in reverse to the next set of cones where you have to do a 180 slide to turn yourself around again. After that you'll have to go around the pylons and do a 360 spin in the last set. It's pretty tricky, but I know you can handle it. Youll have to use a manual transmission to make the 180s, but as long as you stay between the pylons and keep your speed up, everything will be fine.

- **Base String ID**: 3435
- **Tier / Level**: 3
- **Briefing**: Porsche Commercial
- **Raw Parameters**: ints[0..15] = [3435, 0, 3, 3495, 223, 0, 0, 131079, 32, 37, 0, 0, 0, 0, 0, 855638016]

## Mission 31 (ß): The boys out on the race team bashed up this GT 1 pretty good. I just finished patching her up and need this car tested. The weather is too cold and wet at Weissach, so were going to take you and the car with us to a race track in Monaco. You have to complete three laps within the time limit without damaging the car.

- **Base String ID**: 3450
- **Tier / Level**: 3
- **Briefing**: Race Car Test 2
- **Raw Parameters**: ints[0..15] = [3450, 0, 3, 3495, 223, 0, 0, 262152, 196633, 0, 1, 0, 0, 0, 0, 855638016]

## Mission 32 (ß): The Porsche Race Team was so impressed with your lap times that theyve offered you a chance to race against a few of their drivers in a test drive. The reputation of our entire team is riding on you, so dont let us down.

- **Base String ID**: 3500
- **Tier / Level**: 3
- **Briefing**: Dieter
- **Tip**: Porsche Executive
- **Pass Feedback**: 45
- **Fail Feedback**: Dieter is the manager of many departments at the Porsche Factory, one of which is the Porsche Test Team. He recognises that Porsches are among the best performing cars in the world and he expects the same performance from his employees.
- **Raw Parameters**: ints[0..15] = [3500, 0, 3, 3495, 223, 0, 0, 262153, 196626, 0, 2, 0, 0, 0, 0, 855638016]

## Mission 33 (ß): %s, I heard that Klaus is inspecting the first 2000 996 Turbo off the production line in his shop. I was thinking that we should sneak it out for a quick break-in test of our own. Since you think youre so good, you drive and Ill navigate. Just be careful not to scratch it or Klaus will have your head.

- **Base String ID**: 3465
- **Tier / Level**: 3
- **Briefing**: Joy Ride
- **Raw Parameters**: ints[0..15] = [3465, 0, 3, 3495, 223, 0, 0, 196618, 131102, 0, 65537, 0, 0, 0, 0, 855638016]

## Mission 34 (ß): Well, the first of the new turbos are in and Ive got the keys to two of them for the next few days. I told you that youd get your chance at me. If you think youre fast enough, Ill meet you out in town tonight and well see if youre good enough.

- **Base String ID**: 3480
- **Tier / Level**: 3
- **Briefing**: Ace Challenge
- **Raw Parameters**: ints[0..15] = [3480, 0, 3, 3495, 223, 0, 0, 65547, 131098, 0, 2, 0, 0, 0, 0, 855638016]

