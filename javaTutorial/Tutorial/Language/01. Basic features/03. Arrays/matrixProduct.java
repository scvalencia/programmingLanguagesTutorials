public class matrixProduct {

	public static void main(String[] args) {
		int[][] a = { 
					  { 20, 18, 22, 20, 16 },
                      { 18, 20, 18, 21, 20 },
                      { 16, 18, 16, 20, 24 },
                      { 25, 24, 22, 24, 25 }
                     }; // rowA x colA

        int rowA = a.length;
        int colA = a[0].length;

        int[][] b = { 
					  { 20, 18, 22, 20, 16 },
                      { 18, 20, 18, 21, 20 },
                      { 16, 18, 16, 20, 24 },
                      { 25, 24, 22, 24, 25 }
                     }; // rowB x colB

        int rowB = b.length;
        int colAB = b[0].length;

        if(colA != rowB) {
        	System.out.println("Wrong dimensions");
        }
        else {
        	
        }


        // Print Matrix

        /*
         * for(int i = 0; i < 4; i++) {
         *	for(int j = 0; j < 5; j++) {
         * 		System.out.print(a[i][j]);
         *		System.out.print(' ');
         * 	}
         *  System.out.println();
         * }
        */


}