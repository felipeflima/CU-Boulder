#include <iostream>
#include <vector>

#include "Emotion.h"
#include "Creature.h"

// Names: Felipe Lima
//
//


int main() {
    // Part 1 (factory) 
    // ---------------
    // 4) get pointers to one of each type of your Emotion objects via your EmotionFactory. Then,
    // call the Emotion's get_count method to see how many Emotion objects have been instantiated.
    Emotion * Happy = EmotionFactory::GetHappy();
    Emotion * Angry = EmotionFactory::GetAngry();
    Emotion * Joy = EmotionFactory::GetJoy();

    std::cout << "Number of emotions: " << Emotion::get_count << std::endl;
    std::cout << "--------------------" << std::endl;

    // 5) are your EmotionFactory's Get____() methods static or non-static? Do you think that they should
    // be one or the other? Justify your answer. If your methods are static, what would change if they were
    // non-static? If they are non-static, what would change if they were static?

    // EmotionFactory's Get____() methods are static. Have to be static so they can be called without an instance of the EmotionFactory class and if modified it affects all intances.
    // If the methods were non-static, we would need an instance of EmotionFactory to call them.

    // 6) Feel free to create more creatures here
    Creature original_creature(14);
    Creature second_creature(10);
    Creature * third_creature = new Creature(35);

    // 7) Infect your creatures with your emotions. Test out the Creature Spread method.

    original_creature.AddEmotion(Happy);
    original_creature.AddEmotion(Joy);
    second_creature.AddEmotion(Happy);

    std::cout << "OC's emotions" << std::endl;
    for (Emotion * e : original_creature.get_emotions()){
        std::cout << *e << std::endl;
    }

    std::cout << "--------------------" << std::endl;

    std::cout << "OC's emotions" << std::endl;
    for (Emotion * e : original_creature.get_emotions()){
        std::cout << *e << std::endl;
    }

    original_creature.Spread(&second_creature);
    
    std::cout << "second's emotions" << std::endl;
    for (Emotion * s : second_creature.get_emotions()){
        std::cout << *s << std::endl;
    }

    // for (Emotion * d : original_creature.get_emotions() ) {
    //     std::cout << *(d) << std::endl;     
    // }


    // STOP! Turn in Emotion.h, Emotion.cpp, and main.cpp on canvas

 
    // Part 2 (prototype) 
    // ---------------
    // 3) Create some new Creature * objects by using the Creature's Clone() method. Does this method use dynamic dispatch?
    // Answer:
    // How did you test this?

    Creature * c1 = original_creature.Clone();
    Creature * c2 = third_creature->Clone();



    // If you finish:
    // -------------
    // 4) Write a new function in this file void ScienceLab(Creature * original) (not associated with any classes)
    // that takes an original creature and conducts experiments by cloning it and measuring the spread of emotion.
    // You have complete creative freedom here. Feel free to add methods to the Emotion/Creature classes.
    // (The only requirements are the function definition and that you must call Clone() within that function).
    //
    // Call your ScienceLab function as many times as is necessary for your experiments.
}

