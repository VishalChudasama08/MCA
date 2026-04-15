System.out.print("Enter Number Of Students:- ");
            int n = scan.nextInt();

            for (int i = 0; i < n; i++) {
                System.out.println("Enter Details Of Students:- " + (i + 1));
                System.out.print("\nStudent Id:- ");
                int id = scan.nextInt();
                raf.writeInt(id);

                System.out.print("\nStudent Name:- ");
                Scanner scan1 = new Scanner(System.in);
                String name = scan1.nextLine();
                raf.writeUTF(name);

                System.out.print("\nStudent Marks:- ");
                double marks = scan.nextDouble();
                raf.writeDouble(marks);

                System.out.print("\nStudent Grade:- ");
                char grade = scan.next().charAt(0);
                raf.writeChar(grade);
            }