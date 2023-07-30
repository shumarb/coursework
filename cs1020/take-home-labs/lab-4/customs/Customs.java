import java.util.*;

public class Customs {

    private Scanner sc = new Scanner(System.in);
    private boolean isTest = false;
    private int tallest = 0, c, height, count = 0, numQueries, numLeavers, remove = 0;
    private String action;
    private Stack <Person> stack = new Stack <Person>();

    private class Person{
        private int _height;
        private boolean _canSee;

        private Person(){
            this._height = 0;
            this._canSee = false;

        }
        private Person(int height){
            this._height = height;
            this._canSee = false;
        }
    }

    // Print method that displays number of people that can see officer.
    // Precon: count>=0
    // Postcon: NIL
    private void print(int count){
        System.out.println(count);
    }

    // Find tallest person from stack after removals
    // Precon: Stack has gone through editStack method 
    // Postcon: Return tallest person's height
    private int getTallest(Stack<Person>stack){
        for(int w = stack.size() - 1; w >= 0; w--){
            if( stack.get(w)._canSee==true ){
                if(isTest){
                    System.out.println("tallest:" + tallest);
                }
                return stack.get(w)._height;
            }
        }

        // If stack is empty
        return 0;
    }

    // Check number of people leaving that can see officer.
    // Precon: Stack is not empty
    // Postcon: Return number of leavers that can see officer
    private int editStack(Stack<Person> stack, int numLeavers){
        int remove = 0;
        for(int f = 0; f < numLeavers; f++){
            if(isTest){
                System.out.println("Person height: " +
                        (stack.peek())._height + ", canSee: " +
                        (stack.peek())._canSee);
            }

            // Retrieve but don't remove last person from list
            if((stack.peek())._canSee == true){
                remove += 1;
            }

            // Remove person from list
            stack.pop();
        }

        return remove;
    }

    private void run(){
        numQueries = sc.nextInt();

        if(isTest){
            System.out.println("numQueries = " + numQueries);
        }

        for(int i = 0; i < numQueries; i++){
            action = sc.next();

            if(action.equals("leave")){
                numLeavers = sc.nextInt();
                if(isTest){
                    System.out.println("numLeavers = " + numLeavers);
                    System.out.println("Before removing, stack size = " + stack.size());
                }

                // Check how many leavers can see officer, remove this
                // from count
                remove = editStack(stack, numLeavers);
                count -= remove;

                // Get tallest person from edited stack
                tallest = getTallest(stack);

                // Print count
                print(count);
            }

            else{

                // Always read in height and create Person object
                height = sc.nextInt();
                Person person = new Person(height);
                
                // For every entry to stack, check if person is taller
                // than tallest. If yes, number of officers increases by
                // 1, person's canSee status is true, and 
                // tallest is height of latest entry.
                if(person._height>tallest){
                    tallest = person._height;
                    person._canSee = true;
                    count += 1;
                    if(isTest){
                        System.out.println("Person: _height = " + person._height + " , _canSee = " + person._canSee);
                    }
                }

                stack.push(person);
                print(count);
            }
        }
    }

    public static void main(String[] args){
        Customs newCustoms = new Customs();
        newCustoms.run();
    }
}

