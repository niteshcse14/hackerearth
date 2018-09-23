public class Test {
    public static int myMethod()
       {
           try {
                //try block
                return 0;
           }
           finally {
                //finally
                return 1;
           }
           finally 
           {
               return -1;
           }

      }

    public static void main(String[] args) {
        // TODO Auto-generated method stub

         System.out.println(Test.myMethod());
      }
    }
