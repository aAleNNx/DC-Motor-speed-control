from matplotlib import pyplot as plt
import pandas as pd

def plot_data(file_path):
    data = pd.read_csv(file_path)

    nazwa = str(file_path)
    last_part = (nazwa.split('/')[-1]).split('.')[0]
    


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

    plt.subplot(3, 1, 3)
    plt.plot(data['Time'], data['Load'], label='Load Torque', color='red')
    plt.title('Load Torque Over Time')
    plt.xlabel('Time (s)')
    plt.ylabel('Load Torque')
    plt.legend()
    plt.grid()

    plt.tight_layout()
    plt.savefig(f'data/{last_part}.png', dpi = 300)

    print(f"Plot saved as 'data/{last_part}.png'")

if __name__ == "__main__":
    plot_data('data/scenario_disturbance.csv')
    plot_data('data/scenario_heavy_load.csv')
    plot_data('data/scenario_saturation.csv')
    plot_data('data/scenario_setpoint_changes.csv')
    plot_data('data/scenario_step.csv')