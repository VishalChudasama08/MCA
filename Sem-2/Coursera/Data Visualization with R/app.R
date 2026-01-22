library(shiny)
library(ggplot2)

# ---------------- UI ----------------
ui <- fluidPage(
    
    # Task 1: Title (MUST MATCH RUBRIC EXACTLY)
    titlePanel("Trends in Demographics and Income"),
    
    # Task 2: Country dropdown
    fluidRow(
        column(
            12,
            selectInput(
                "country",
                "Select Country:",
                choices = c(
                    "United-States",
                    "Canada",
                    "Mexico",
                    "Germany",
                    "Philippines"
                ),
                selected = "United-States"
            )
        )
    ),
    
    # Task 3: Continuous variables
    fluidRow(
        column(
            6,
            radioButtons(
                "cont_var",
                "Continuous Variable:",
                choices = c("age", "hours_per_week"),
                selected = "age"
            )
        ),
        column(
            6,
            radioButtons(
                "cont_plot",
                "Graph Type:",
                choices = c("boxplot", "histogram"),
                selected = "boxplot"
            )
        )
    ),
    
    # Task 4: Categorical variables
    fluidRow(
        column(
            6,
            radioButtons(
                "cat_var",
                "Categorical Variable:",
                choices = c("education", "workclass", "sex"),
                selected = "workclass"
            )
        ),
        column(
            6,
            checkboxInput(
                "stacked",
                "Stacked Bar Chart",
                value = FALSE
            )
        )
    ),
    
    # Plots
    fluidRow(
        column(6, plotOutput("contPlot")),
        column(6, plotOutput("catPlot"))
    )
)

# ---------------- SERVER ----------------
server <- function(input, output) {
    
    # Fake Adult-like dataset WITH income (prediction)
    set.seed(123)
    data <- data.frame(
        age = sample(18:70, 300, replace = TRUE),
        hours_per_week = sample(20:60, 300, replace = TRUE),
        education = sample(c("Bachelors", "HS-grad", "Masters"), 300, replace = TRUE),
        workclass = sample(c("Private", "Self-emp", "Gov"), 300, replace = TRUE),
        sex = sample(c("Male", "Female"), 300, replace = TRUE),
        prediction = sample(c("<=50K", ">50K"), 300, replace = TRUE),
        country = sample(
            c("United-States", "Canada", "Mexico", "Germany", "Philippines"),
            300,
            replace = TRUE
        )
    )
    
    # Filter by country
    filtered_data <- reactive({
        data[data$country == input$country, ]
    })
    
    # ---------- Task 5: Continuous plots ----------
    output$contPlot <- renderPlot({
        
        df <- filtered_data()
        
        if (input$cont_var == "age" && input$cont_plot == "boxplot") {
            
            # Task 5.1: Faceted boxplot for age
            ggplot(df, aes(y = age)) +
                geom_boxplot(fill = "skyblue") +
                facet_wrap(~prediction) +
                labs(y = "age") +
                theme_minimal()
            
        } else if (input$cont_var == "hours_per_week" && input$cont_plot == "histogram") {
            
            # Task 5.2: Faceted histogram for hours_per_week
            ggplot(df, aes(x = hours_per_week)) +
                geom_histogram(fill = "steelblue", color = "black", bins = 15) +
                facet_wrap(~prediction) +
                labs(x = "hours_per_week") +
                theme_minimal()
        }
    })
    
    # ---------- Task 6: Categorical plots ----------
    output$catPlot <- renderPlot({
        
        df <- filtered_data()
        
        if (input$cat_var == "workclass" && !input$stacked) {
            
            # Task 6.1: Faceted unstacked bar chart (workclass)
            ggplot(df, aes(x = workclass, fill = workclass)) +
                geom_bar() +
                facet_wrap(~prediction) +
                theme_minimal() +
                theme(
                    legend.position = "bottom",
                    axis.text.x = element_text(angle = 45, hjust = 1)
                )
            
        } else if (input$cat_var == "education" && input$stacked) {
            
            # Task 6.2: Stacked bar chart (education)
            ggplot(df, aes(x = education, fill = prediction)) +
                geom_bar() +
                theme_minimal() +
                theme(
                    legend.position = "bottom",
                    axis.text.x = element_text(angle = 45, hjust = 1)
                )
        }
    })
}

# ---------------- RUN APP ----------------
shinyApp(ui = ui, server = server)
