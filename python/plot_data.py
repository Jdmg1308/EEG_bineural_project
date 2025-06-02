import pandas as pd
import matplotlib as plt

def plot_brainwave_data_2D(file_path="data/eeg_audio_log.csv", start_time="13:24:24", end_time="13:45:08"):
    """Reads EEG data and visualizes all 20 channels in a clean grid layout."""
    try:
        df = pd.read_csv(file_path)

        if df.empty:
            print(" No data found in the file. Ensure logging is running.")
            return

        #df["Delta_Power"] = df["Delta_Power"].apply(ast.literal_eval)

        df["Timestamp"] = pd.to_datetime(df["Timestamp"].str.strip(), format="%H:%M:%S", errors='coerce')
        df.dropna(subset=["Timestamp"], inplace=True)  # Remove any rows where timestamp couldn't be parsed

        print("First 5 timestamps in data:", df["Timestamp"].head())
        print("Last 5 timestamps in data:", df["Timestamp"].tail())


        start_time = pd.to_datetime("13:24:24", format="%H:%M:%S")
        end_time = pd.to_datetime("13:45:08", format="%H:%M:%S")
        df = df[(df["Timestamp"] >= start_time) & (df["Timestamp"] <= end_time)]

        if df.empty:
            print(f"⚠ No data in the selected range {start_time} - {end_time}")
            return

        eeg_values = pd.DataFrame(df["Delta_Power"].to_list(), index=df["Timestamp"])

        fig, axes = plt.subplots(4, 5, figsize=(15, 10), sharex=True, sharey=True)
        fig.suptitle(f"EEG Brainwave Data Over Time ({start_time} to {end_time})", fontsize=14)

        axes = axes.ravel()

        # Plot each EEG channel in its own subplot
        for i in range(20):
            axes[i].plot(eeg_values.index, eeg_values[i], label=f"EEG {i+1}", color="b", linewidth=1)
            axes[i].set_title(f"EEG {i+1}")
            axes[i].grid(True)

        plt.xticks(rotation=45)
        plt.tight_layout(rect=[0, 0.03, 1, 0.95]) 
        plt.show()

    except FileNotFoundError:
        print("⚠ Log file not found. Make sure data is being recorded.")
    except Exception as e:
        print(f"⚠ Error loading data: {e}")

def plot_brainwave_data(file_path="data/eeg_audio_log.csv"):
    """Reads logged EEG data and visualizes it in a 3D plot."""
    try:
        df = pd.read_csv(file_path)

        if df.empty:
            print("⚠ No data found in the file. Ensure logging is running.")
            return
        
        # Create 3D plot
        fig = plt.figure()
        ax = fig.add_subplot(111, projection='3d')

        df = df.sort_values(by="Delta_Power")  # Adjust sorting column if necessary

        # Extract columns
        x = df["Delta_Power"].values
        y = df["Phase_Shift"].values
        z = df["Frequency"].values

        ax.plot3D(x, y, z, c='b', marker='o', linestyle='-', linewidth=1)

        # Labels
        ax.set_xlabel("Delta Brainwave Change")
        ax.set_ylabel("Phase Shift (°)")
        ax.set_zlabel("Frequency (Hz)")
        plt.title("EEG Brainwave Response to Phase & Frequency Shifts")

        plt.show()

    except FileNotFoundError:
        print("⚠ Log file not found. Make sure data is being recorded.")
    except Exception as e:
        print(f"⚠ Error loading data: {e}")

if __name__ == "__main__":
    plot_brainwave_data_2D()