# Install the Google AI Python SDK
# $ pip install google-generativeai

import google.generativeai as genai

def getSubject(mailContent):
    genai.configure(api_key="GOOGLE_API_KEY")
    generation_config = {
        "temperature": 1,
        "top_p": 0.95,
        "top_k": 64,
        "max_output_tokens": 8192,
        "response_mime_type": "text/plain",
    }
    model = genai.GenerativeModel(
        model_name="gemini-1.5-pro",
        generation_config=generation_config,
        # safety_settings = Adjust safety settings if necessary
    )
    response = model.generate_content([
      "input: Generate a professional subject line for responding to the following customer feedback email:\n\nFeedback Email:\nSUBJECT: Feedback and Suggestions for Improving Your Store\nBODY:\nHello Zenith Commerce Team,\n\nI have been shopping with your store for a while now and generally have a positive experience. However, I wanted to offer a few suggestions that I think could improve your service:\n\n1. Website Navigation: Adding more detailed filters on your site would make it easier to find specific products.\n2. Customer Loyalty Program: Implementing a rewards program for repeat customers would be a great incentive.\n3. Mobile App: A dedicated mobile app could make shopping more convenient for mobile users.\n\nI hope you find these suggestions useful. Thank you for continuously striving to improve your services.\n\nBest regards,\nJames Lee",
      "output: Enhancing Your Shopping Experience: Your Valuable Feedback and Our Commitment",        
      "input: Generate a professional subject line (only one Subject and don't include the word subject in output and give subject in one line and without formating using ** ) for responding to the following customer feedback email:\n\nFeedback Email:\n" + mailContent,
      "\noutput: "
    ])

    return (response.text).splitlines()[0]

def getMailBody(mailContent):
    genai.configure(api_key="AIzaSyDJhUvjfAZ65z1k6YpUwd7jolMLoiHrE9Y")
    generation_config = {
        "temperature": 1,
        "top_p": 0.95,
        "top_k": 64,
        "max_output_tokens": 8192,
        "response_mime_type": "text/plain",
    }
    model = genai.GenerativeModel(
        model_name="gemini-1.5-pro",
        generation_config=generation_config,
        # safety_settings = Adjust safety settings if necessary
    )
    response = model.generate_content([
    "input: Generate a professional response email body based on the following customer feedback email:\n\nFeedback Email:\nSUBJECT: Feedback and Suggestions for Improving Your Store\nBODY:\nHello Zenith Commerce Team,\n\nI have been shopping with your store for a while now and generally have a positive experience. However, I wanted to offer a few suggestions that I think could improve your service:\n\n1. Website Navigation: Adding more detailed filters on your site would make it easier to find specific products.\n2. Customer Loyalty Program: Implementing a rewards program for repeat customers would be a great incentive.\n3. Mobile App: A dedicated mobile app could make shopping more convenient for mobile users.\n\nI hope you find these suggestions useful. Thank you for continuously striving to improve your services.\n\nBest regards,\nJames Lee",
    "output: Dear James Lee,\n\nThank you for your valuable feedback and for being a loyal customer of Zenith Commerce. We appreciate your positive experience and your thoughtful suggestions for improving our services.\n\n1. Website Navigation: We understand the importance of an easy-to-navigate website. Our team is working on implementing more detailed filters to help customers find specific products more efficiently.\n2. Customer Loyalty Program: We agree that a rewards program would be a great incentive for our repeat customers. We are currently exploring options to implement a customer loyalty program soon.\n3. Mobile App: We are also considering the development of a dedicated mobile app to enhance the shopping experience for our mobile users.\n\nYour suggestions are very important to us, and we are committed to continuously improving our services. Thank you for helping us strive for excellence.\n\nBest regards,\n\nAshwin R \nCustomer Support Team  \nZenith Commerce",        
    "input: Generate a professional response email body based on the following customer feedback email:\n\nFeedback Email:\n" + mailContent,
    "\noutput: "
    ])

    return response.text
