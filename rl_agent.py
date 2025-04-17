import numpy as np
import random

class BrainwaveRLAgent:
    def __init__(self, learning_rate=0.1, discount_factor=0.9, exploration_rate=0.2):
        """Reinforcement Learning Agent for optimizing audio feedback."""
        self.q_table = {}  # Maps (delta_power) -> (phase_shift, frequency)
        self.learning_rate = learning_rate
        self.discount_factor = discount_factor
        self.exploration_rate = exploration_rate

    def choose_action(self, delta_power):
        """Selects phase shift and frequency based on exploration/exploitation."""
        if random.uniform(0, 1) < self.exploration_rate or delta_power not in self.q_table:
            # Explore: Random phase shift and frequency
            phase_shift = random.uniform(0, np.pi)
            frequency_change = random.uniform(0.9, 1.1)
        else:
            # Exploit: Choose best known values
            phase_shift, frequency_change = self.q_table[delta_power]
        
        return phase_shift, frequency_change

    def update_q_table(self, old_delta, new_delta, phase_shift, frequency_change, reward):
        """Updates Q-values using the Bellman equation."""
        old_q_value = self.q_table.get(old_delta, (0, 0))[1]
        best_future_q = max(self.q_table.get(new_delta, (0, 0))[1], 0)

        # Q-Learning Update Rule
        new_q_value = old_q_value + self.learning_rate * (reward + self.discount_factor * best_future_q - old_q_value)
        self.q_table[old_delta] = (phase_shift, frequency_change, new_q_value)

    def calculate_reward(self, old_brainwaves, new_brainwaves):
        """Reward based on relative relationships between brainwave bands."""
        old_gamma, old_beta, old_alpha, old_theta, old_delta = old_brainwaves
        new_gamma, new_beta, new_alpha, new_theta, new_delta = new_brainwaves

        # Compute ratios and differences
        old_theta_beta_ratio = old_theta / (old_beta + 1e-5) 
        new_theta_beta_ratio = new_theta / (new_beta + 1e-5)

        old_delta_gamma_diff = old_delta - old_gamma
        new_delta_gamma_diff = new_delta - new_gamma

        # Reward based on improvements
        reward = 0

        if new_theta_beta_ratio > old_theta_beta_ratio:
            reward += 1

        if new_delta_gamma_diff > old_delta_gamma_diff:
            reward += 1

        if new_beta > new_theta:
            reward -= 1

        return reward

