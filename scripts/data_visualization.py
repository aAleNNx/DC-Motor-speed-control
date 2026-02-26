from matplotlib import pyplot as plt
import pandas as pd

def plot_data(file_path):
    data = pd.read_csv(file_path)
    
    plt.figure(figsize=(12, 8))
    
    plt.subplot(3, 1, 1)
    plt.plot(data['Time'], data['Setpoint'], label='Setpoint', color='blue')
    plt.plot(data['Time'], data['Speed'], label='Speed', color='orange')
    plt.title('Setpoint vs Speed')
    plt.xlabel('Time (s)')
    plt.ylabel('Value')
    plt.legend()
    plt.grid()
    
    plt.subplot(3, 1, 2)
    plt.plot(data['Time'], data['Control'], label='Control Signal', color='green')
    plt.title('Control Signal Over Time')
    plt.xlabel('Time (s)')
    plt.ylabel('Control Signal')
    plt.legend()
    plt.grid()
    
    plt.tight_layout()
    plt.savefig('data/response.png', dpi = 300)

if __name__ == "__main__":
    plot_data('data/simulation_data.csv')