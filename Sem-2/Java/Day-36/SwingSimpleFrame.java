import javax.swing.*;

class SwingSimpleFrame {
    public static void main(String args[]) {
        JFrame frm = new JFrame("First");

        frm.setSize(500, 500);
        frm.setLayout(null);
        frm.setVisible(true);

        JButton btnSubmit = new JButton("submit");
        btnSubmit.setBounds(50, 100, 100, 30);

        JButton btnCancel = new JButton("cancel");
        btnCancel.setBounds(200, 100, 100, 30);

        frm.add(btnSubmit);
        frm.add(btnCancel);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}