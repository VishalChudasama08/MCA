import matplotlib.pyplot as plt

# Read project data from file
def read_projects(filename):
    projects = []
    with open(filename, 'r') as file:
        for line in file:
            parts = line.split(',')  # No strip()
            if len(parts) == 5:
                proj = {
                    'Proj_Code': parts[0],
                    'Duration': int(parts[1]),
                    'Team_Size': int(parts[2]),
                    'Client_Country': parts[3].lower().replace('\n', ''),  # only clean newline
                    'Budget': int(parts[4])
                }
                projects.append(proj)
    return projects

# Longest running project
def longest_project(projects):
    return max(projects, key=lambda x: x['Duration'])

# Largest team size project
def largest_team_project(projects):
    return max(projects, key=lambda x: x['Team_Size'])

# Projects with Australian clients
def australian_projects(projects):
    return [proj for proj in projects if proj['Client_Country'] == 'australia']

# Bar graph for project budgets
def plot_budget_graph(projects):
    codes = [p['Proj_Code'] for p in projects]
    budgets = [p['Budget'] for p in projects]

    plt.figure(figsize=(8,5))
    plt.bar(codes, budgets, color='green')
    plt.title("Project Budgets")
    plt.xlabel("Project Code")
    plt.ylabel("Budget")
    plt.grid(axis='y')
    plt.tight_layout()
    plt.show()

# Main logic
filename = "projects.txt"
project_data = read_projects(filename)

print("1. Longest Running Project:", longest_project(project_data))
print("2. Largest Team Size Project:", largest_team_project(project_data))

print("3. Projects with Australian Clients:")
for proj in australian_projects(project_data):
    print(proj)

plot_budget_graph(project_data)
