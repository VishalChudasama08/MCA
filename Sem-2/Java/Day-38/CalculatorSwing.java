import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CalculatorSwing {

    private final static int NBUTTONS = 18;

    String buttonLabels[] = {
        "7", "8", "9", 
		"4", "5", "6",
        "1", "2", "3", 
		"0", ".", "=",
        "+", "-", "+/-", 
		"*", "/", "C"
    };

    JButton buttons[];
    JTextField tf;

    String operator = "";
    double register1 = 0, register2 = 0;
    boolean overwriteDisplay = false;

    CalculatorSwing() {

        JFrame frame = new JFrame("Calculator");
        frame.setSize(350, 350);
        frame.setLayout(new BorderLayout());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Top display
        JPanel topPanel = new JPanel();
        tf = new JTextField(20);
        tf.setEditable(false);
        tf.setFont(new Font("Arial", Font.BOLD, 18));
        topPanel.add(tf);
        frame.add(topPanel, BorderLayout.NORTH);

        // Buttons panel
        JPanel gridPanel = new JPanel();
        gridPanel.setLayout(new GridLayout(6, 3, 5, 5));

        buttons = new JButton[NBUTTONS];

        for (int i = 0; i < NBUTTONS; i++) {
            buttons[i] = new JButton(buttonLabels[i]);

            buttons[i].addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					handleClick(e.getActionCommand());
				}
			});

            gridPanel.add(buttons[i]);
        }

        frame.add(gridPanel, BorderLayout.CENTER);

        frame.setVisible(true);
    }

    private void handleClick(String ac) {

        // Clear
        if (ac.equals("C")) {
            tf.setText("");
            operator = "";
            register1 = 0;
            register2 = 0;
            return;
        }

        // +/- toggle
        if (ac.equals("+/-")) {
            String s = tf.getText();
            if (s.startsWith("-"))
                tf.setText(s.substring(1)); // remove - (minus)
            else
                tf.setText("-" + s); // add - (minus)
            return;
        }

        // Decimal
        if (ac.equals(".")) {
            if (overwriteDisplay) {
                tf.setText(".");
                overwriteDisplay = false;
                return;
            }
            if (!tf.getText().contains(".")) {
                tf.setText(tf.getText() + ".");
            }
            return;
        }

        // Digits
        if (ac.matches("[0-9]")) {
            if (overwriteDisplay)
                tf.setText(ac);
            else
                tf.setText(tf.getText() + ac);

            overwriteDisplay = false;
            return;
        }

        // Operators
        if (ac.equals("+") || ac.equals("-") ||
            ac.equals("*") || ac.equals("/") ||
            ac.equals("=")) {

            if (!tf.getText().isEmpty()) {
                register2 = Double.parseDouble(tf.getText());
                register1 = calculate(operator, register1, register2);
                tf.setText("" + register1);
                operator = ac;
                overwriteDisplay = true;
            }
        }
    }

    private double calculate(String op, double r1, double r2) {
        switch (op) {
            case "+": return r1 + r2;
            case "-": return r1 - r2;
            case "*": return r1 * r2;
            case "/": return r1 / r2;
            default: return r2;
        }
    }

    public static void main(String[] args) {
        new CalculatorSwing(); 
    }
}